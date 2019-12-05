#ifndef PROPS_SABER_ISHTOB_BUTTONS_H
#define PROPS_SABER_ISHTOB_BUTTONS_H

#include "prop_base.h"

#undef PROP_TYPE
#define PROP_TYPE SaberIshtobButtons

// The Saber class implements the basic states and actions
// for the saber.
class SaberIshtobButtons : public PropBase {
public:
  SaberIshtobButtons() : PropBase() {}
  const char* name() override { return "SaberIshtobButtons"; }

//Volume change - function adopted from sa22c
  void ChangeVolume(bool up) {
    if (up) {
      STDOUT.println("Volume up");
      if (dynamic_mixer.get_volume() < MAX_VOLUME) {
        dynamic_mixer.set_volume(std::min<int>(MAX_VOLUME,
          dynamic_mixer.get_volume() + 100));
        beeper.Beep(0.3, 500);
        STDOUT.print("Current Volume: ");
        STDOUT.println(dynamic_mixer.get_volume());
        SaveGlobalState();
      }
      else {
        beeper.Beep(0.1, 500);
        beeper.Beep(0.1, 0);
        beeper.Beep(0.1, 500);
        STDOUT.print("Max Volume Reached: ");
        STDOUT.println(dynamic_mixer.get_volume());
      }
    } else {
      STDOUT.println("Volume Down");
      if (dynamic_mixer.get_volume() > MIN_VOLUME) {
        dynamic_mixer.set_volume(std::max<int>(MIN_VOLUME,
          dynamic_mixer.get_volume() - 100));
        beeper.Beep(0.3, 500);
        STDOUT.print("Current Volume: ");
        STDOUT.println(dynamic_mixer.get_volume());
        SaveGlobalState();
      }
      else{
        STDOUT.print("Min Volume Reached: ");
        STDOUT.println(dynamic_mixer.get_volume());
        beeper.Beep(0.1, 500);
        beeper.Beep(0.1, 0);
        beeper.Beep(0.1, 500);
      }
    }
  }


  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {
      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_ON):
        if (accel_.x < -0.15) {
          pointing_down_ = true;
        } else {
          pointing_down_ = false;
        }
      return true;
// Blade On
#if NUM_BUTTONS == 0
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF):
#endif
      case EVENTID(BUTTON_POWER, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF):
      case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_OFF):
    if (mode_volume_){
      mode_volume_ = false;
      beeper.Beep(0.2, 3000);
      beeper.Beep(0.3, 200);
      STDOUT.println("Exit Volume Menu");
    }
    else{
        aux_on_ = false;
        On();
    }
  return true;
//Blade Detection

#ifdef BLADE_DETECT_PIN
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_OFF):
  // Might need to do something cleaner, but let's try this for now.
  blade_detected_ = true;
  FindBladeAgain();
  SaberBase::DoBladeDetect(true);
  return true;
  
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_OFF):
  // Might need to do something cleaner, but let's try this for now.
  blade_detected_ = false;
  FindBladeAgain();
  SaberBase::DoBladeDetect(false);
  return true;
#endif   

//Next Preset
      case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_OFF):
#ifdef DUAL_POWER_BUTTONS
        aux_on_ = true;
        On();
#else
        next_preset();
#endif
  return true;
// Volume Adjustment
      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_AUX2):
    if (mode_volume_){
      mode_volume_ = false;
      beeper.Beep(0.2, 3000);
      beeper.Beep(0.3, 200);
      STDOUT.println("Exit Volume Menu");
    }
    else{
      mode_volume_ = true;
      beeper.Beep(0.2, 3000);
      beeper.Beep(0.3, 3000);
      STDOUT.println("Enter Volume Menu");
    }
    return true;
      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
         if (mode_volume_) {
          ChangeVolume(true);
         }
      return true;

      case EVENTID(BUTTON_AUX2, EVENT_CLICK_SHORT, MODE_OFF):
         if (mode_volume_) {
          ChangeVolume(false);
         }
      return true;

//Activate Mute Mode
      case EVENTID(BUTTON_POWER, EVENT_DOUBLE_CLICK, MODE_ON):
  if (millis() - activated_ < 500) {
    if (SetMute(true)) {
      unmute_on_deactivation_ = true;
    }
  }
  return true;
  //Power Off
      case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_ON):
      case EVENTID(BUTTON_POWER, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_OFF, MODE_ON):
#if NUM_BUTTONS == 0
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON):
#endif
#ifndef DISABLE_COLOR_CHANGE
  if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
    // Just exit color change mode.
    // Don't turn saber off.
    ToggleColorChangeMode();
    return true;
  }
#endif
      if (!SaberBase::Lockup()) {
        Off();
      }
        return true;


      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON | BUTTON_POWER):
        SaberBase::DoForce();
  return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON):
        // Avoid the base and the very tip.
  // TODO: Make blast only appear on one blade!
        SaberBase::DoBlast();
  return true;

#if NUM_BUTTONS == 1
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON | BUTTON_POWER):
#endif
#ifndef DISABLE_COLOR_CHANGE
      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX2):
  ToggleColorChangeMode();
  break;
#endif

        // Lockup
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_AUX):
        if (!SaberBase::Lockup()) {
          if (pointing_down_) {
            SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          } else {
            SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
          }
          SaberBase::DoBeginLockup();
    return true;
        }
        break;

        // Stab Lockup? Long-Stab? Touche?
      case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_POWER):
      case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_AUX):
        if (!SaberBase::Lockup()) {
    // TODO: Make it possible to distinguish between drag and long-stab.
    SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          SaberBase::DoBeginLockup();
    return true;
        }
        break;

        // Off functions
      case EVENTID(BUTTON_AUX, EVENT_DOUBLE_CLICK, MODE_OFF):
        if (!mode_volume_){
         StartOrStopTrack();
        }
  return true;

      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
        SaberBase::RequestMotion();
  return true;

      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
#if NUM_BUTTONS == 0
      case EVENTID(BUTTON_NONE, EVENT_SHAKE, MODE_OFF):
#endif      
        next_preset();
  return true;

      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_AUX):
        previous_preset();
  return true;

      case EVENTID(BUTTON_AUX2, EVENT_HELD_LONG, MODE_OFF):
#ifdef DUAL_POWER_BUTTONS
        next_preset();
#else
        previous_preset();
#endif
  return true;

  // Events that needs to be handled regardless of what other buttons
  // are pressed.
      case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
  if (SaberBase::Lockup()) {
    SaberBase::DoEndLockup();
    SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
    return true;
  }
    }
    return false;
  }
private:
  bool aux_on_ = true;
  bool pointing_down_ = false;
  bool mode_volume_ = false;

};

#endif
