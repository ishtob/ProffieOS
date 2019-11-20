#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
#define VOLUME 2000
const unsigned int maxLedsPerStrip = 192;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SSD1306
#define ENABLE_SERIAL
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin1,bladePowerPin2,bladePowerPin3>
#endif

#ifdef CONFIG_PROP
#include "../props/saber_ishtob_buttons.h"

#endif

#ifdef CONFIG_PROP
#include "../props/saber_ishtob_buttons.h"
#endif

#ifdef CONFIG_PRESETS
//Creates BatteryLevelStyle to use within blade styles

using BatteryLevelStyle =Mix<Sin<Int<20>,Int<8192>,Int<32768>>,Black,Mix<BatteryLevel,Red,Red,Orange,Orange,Yellow,Yellow,Green,Green,Green,Blue,Blue,Blue>>;

Preset presets[] = {
{ "Balance", "tracks/March.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<37247,37798,50393>,Rgb16<56306,28268,31966>>,AudioFlicker<Rgb16<37247,37798,50393>,Rgb16<28268,39681,56306>>,AudioFlicker<Rgb16<37247,37798,50393>,White>>,White>,InOutFuncX<Int<300>,Int<800>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<37247,37798,50393>,Rgb16<56306,28268,31966>>,AudioFlicker<Rgb16<37247,37798,50393>,Rgb16<28268,39681,56306>>,AudioFlicker<Rgb16<37247,37798,50393>,White>>,White>,InOutFuncX<Int<300>,Int<800>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<37247,37798,50393>,Rgb16<56306,28268,31966>>,AudioFlicker<Rgb16<37247,37798,50393>,Rgb16<28268,39681,56306>>,AudioFlicker<Rgb16<37247,37798,50393>,White>>,White>,InOutFuncX<Int<300>,Int<800>>>>(), "white"},
{ "Balance", "tracks/March.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb<200,0,200>,Rgb<255,100,255>>,AudioFlicker<Rgb<200,0,200>,Rgb<255,100,255>>,AudioFlicker<Rgb<200,0,200>,Rgb16<38402,8357,38402>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb<200,0,200>,Rgb<255,100,255>>,AudioFlicker<Rgb<200,0,200>,Rgb<255,100,255>>,AudioFlicker<Rgb<200,0,200>,Rgb16<38402,8357,38402>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb<200,0,200>,Rgb<255,100,255>>,AudioFlicker<Rgb<200,0,200>,Rgb<255,100,255>>,AudioFlicker<Rgb<200,0,200>,Rgb16<38402,8357,38402>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(), "violet"},
{ "SmthJedi", "tracks/mercury.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<0,0,51919>,Rgb16<8357,8357,65535>>,AudioFlicker<Rgb16<0,0,51919>,Rgb16<8357,8357,65535>>,AudioFlicker<Rgb16<0,0,51919>,Rgb16<1818,1818,38402>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<0,0,51919>,Rgb16<8357,8357,65535>>,AudioFlicker<Rgb16<0,0,51919>,Rgb16<8357,8357,65535>>,AudioFlicker<Rgb16<0,0,51919>,Rgb16<1818,1818,38402>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<0,0,51919>,Rgb16<8357,8357,65535>>,AudioFlicker<Rgb16<0,0,51919>,Rgb16<8357,8357,65535>>,AudioFlicker<Rgb16<0,0,51919>,Rgb16<1818,1818,38402>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(), "blue"},
{ "SmthJedi", "tracks/mercury.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<0,51919,0>,Rgb16<8357,65535,8357>>,AudioFlicker<Rgb16<0,51919,0>,Rgb16<8357,65535,8357>>,AudioFlicker<Rgb16<0,51919,0>,Rgb16<1818,38402,1818>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<0,51919,0>,Rgb16<8357,65535,8357>>,AudioFlicker<Rgb16<0,51919,0>,Rgb16<8357,65535,8357>>,AudioFlicker<Rgb16<0,51919,0>,Rgb16<1818,38402,1818>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<0,51919,0>,Rgb16<8357,65535,8357>>,AudioFlicker<Rgb16<0,51919,0>,Rgb16<8357,65535,8357>>,AudioFlicker<Rgb16<0,51919,0>,Rgb16<1818,38402,1818>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(), "green"},
{ "SmthGrey", "tracks/mercury.wav",
StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Rgb16<65535,37562,0>,Rgb16<65535,0,0>>,AudioFlicker<Rgb16<65535,37562,0>,White>,AudioFlicker<Rgb16<65535,37562,0>,Rgb16<65535,37562,10000>>>,White>,300,800>>(),
StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Rgb16<65535,37562,0>,Rgb16<65535,0,0>>,AudioFlicker<Rgb16<65535,37562,0>,White>,AudioFlicker<Rgb16<65535,37562,0>,Rgb16<65535,37562,10000>>>,White>,300,800>>(),
StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Rgb16<65535,37562,0>,Rgb16<65535,0,0>>,AudioFlicker<Rgb16<65535,37562,0>,White>,AudioFlicker<Rgb16<65535,37562,0>,Rgb16<65535,37562,10000>>>,White>,300,800>>(), "yellow"},
{ "RgueCmdr", "tracks/March.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<51919,0,0>,Rgb16<65535,8357,8357>>,AudioFlicker<Rgb16<51919,0,0>,Rgb16<65535,8357,8357>>,AudioFlicker<Rgb16<51919,0,0>,Rgb16<38402,1818,1818>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<51919,0,0>,Rgb16<65535,8357,8357>>,AudioFlicker<Rgb16<51919,0,0>,Rgb16<65535,8357,8357>>,AudioFlicker<Rgb16<51919,0,0>,Rgb16<38402,1818,1818>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<51919,0,0>,Rgb16<65535,8357,8357>>,AudioFlicker<Rgb16<51919,0,0>,Rgb16<65535,8357,8357>>,AudioFlicker<Rgb16<51919,0,0>,Rgb16<38402,1818,1818>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(), "red"},
{ "SmthFuzz", "tracks/mercury.wav",
StylePtr<InOutSparkTip<LocalizedClash<Lockup<OriginalBlast<InOutHelper<SimpleClash<Lockup<Rainbow,AudioFlicker<Rainbow,White>,AudioFlicker<Rainbow,White>>,White,100>,450,1200,Black>,White>,AudioFlicker<InOutHelper<SimpleClash<Lockup<Rainbow,AudioFlicker<Rainbow,White>,AudioFlicker<Rainbow,White>>,White,100>,450,1200,Black>,White>,AudioFlicker<Blue,White>>,White,100,50>,500,1200,White>>(),
StylePtr<InOutSparkTip<LocalizedClash<Lockup<OriginalBlast<InOutHelper<SimpleClash<Lockup<Rainbow,AudioFlicker<Rainbow,White>,AudioFlicker<Rainbow,White>>,White,100>,450,1200,Black>,White>,AudioFlicker<InOutHelper<SimpleClash<Lockup<Rainbow,AudioFlicker<Rainbow,White>,AudioFlicker<Rainbow,White>>,White,100>,450,1200,Black>,White>,AudioFlicker<Blue,White>>,White,100,50>,500,1200,White>>(),
StylePtr<InOutSparkTip<LocalizedClash<Lockup<OriginalBlast<InOutHelper<SimpleClash<Lockup<Rainbow,AudioFlicker<Rainbow,White>,AudioFlicker<Rainbow,White>>,White,100>,450,1200,Black>,White>,AudioFlicker<InOutHelper<SimpleClash<Lockup<Rainbow,AudioFlicker<Rainbow,White>,AudioFlicker<Rainbow,White>>,White,100>,450,1200,Black>,White>,AudioFlicker<Blue,White>>,White,100,50>,500,1200,White>>(), "rainbow"},
{ "TeensySF", "tracks/venus.wav",
&style_pov,
StyleNormalPtr<BLACK, BLACK, 300, 800>(),
StyleNormalPtr<BLACK, BLACK, 300, 800>(), "POV"},
{ "TthCrstl", "tracks/mars.wav",
&style_charging,
StyleNormalPtr<BLACK, BLACK, 300, 800>(),
StyleNormalPtr<BLACK, BLACK, 300, 800>(), "Battery\nLevel"}
};
BladeConfig blades[] = {
 { 5100,
 	WS281XBladePtr<112, bladePin, Color8::GRBw, PowerPINS<bladePowerPin1,bladePowerPin2,bladePowerPin3> >(), //main blade
    WS2811BladePtr<5, WS2811_ACTUALLY_800kHz | WS2811_GRB, blade2Pin, PowerPINS<bladePowerPin4> >(), //shotk NPXL
    WS281XBladePtr<1, blade3Pin, Color8::GRBw, PowerPINS<bladePowerPin6> >(),// crystal chamber
    CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif