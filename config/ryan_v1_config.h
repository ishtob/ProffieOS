#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 3
#define VOLUME 1300
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
#endif

#ifdef CONFIG_PROP
#include "../props/saber_ishtob_buttons.h"
#endif

#ifdef CONFIG_PRESETS

//Creates BatteryLevelStyle to use within blade styles
using BatteryLevelStyle =Mix<Sin<Int<20>,Int<8192>,Int<32768>>,Black,Mix<BatteryLevel,Red,Red,Red,Orange,Orange,Orange,Rgb16<64971,33514,829>,Rgb16<64971,33514,829>,Rgb16<64971,33514,829>,Green,Green,Green>>;

Preset presets[] = {
{ "LS6", "tracks/luke_intro.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<AudioFlicker<Green,Rgb16<1818,52226,1818>>,Rgb16<65535,17521,17521>>,AudioFlicker<Green,White>,AudioFlicker<Green,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Green,Rgb16<65535,17521,17521>>,AudioFlicker<Green,White>,AudioFlicker<Green,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Green, Black, 3000>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Green, Black>, ColorSequence<1000, Black, Red>>>(), "Luke\nGreen"},
{ "LS6", "tracks/medley1.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<AudioFlicker<Blue,Rgb16<1818,1818,52226>>,Rgb16<65535,17521,17521>>,AudioFlicker<Blue,White>,AudioFlicker<Blue,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Blue,Rgb16<17521,17521,65535>>,AudioFlicker<Blue,White>,AudioFlicker<Blue,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Blue, Black, 3000>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Blue, Black>, ColorSequence<1000, Black, Red>>>(), "Luke\nBlue"},
{ "Balance", "tracks/medley1.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<AudioFlicker<Rgb16<22546,0,47361>,Rgb16<52226,1818,52226>>,Rgb16<65535,17521,17521>>,AudioFlicker<Rgb16<22546,0,47361>,White>,AudioFlicker<Rgb16<22546,0,47361>,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<22546,0,47361>,Rgb16<65535,17521,65535>>,AudioFlicker<Rgb16<22546,0,47361>,White>,AudioFlicker<Rgb16<22546,0,47361>,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Rgb16<22546,0,47361>, Black, 3000>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Rgb16<22546,0,47361>, Black>, ColorSequence<1000, Black, Red>>>(), "Balance\nPurple"},
{ "Balance", "tracks/medley1.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<AudioFlicker<Rgb16<64971,33514,829>,Rgb16<52226,52226,1818>>,Rgb16<65535,17521,17521>>,AudioFlicker<Rgb16<64971,33514,829>,White>,AudioFlicker<Rgb16<64971,33514,829>,Rgb16<65535,62191,65535>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<64971,33514,829>,Rgb16<65535,65535,17521>>,AudioFlicker<Rgb16<64971,33514,829>,White>,AudioFlicker<Rgb16<64971,33514,829>,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Rgb16<64971,33514,829>, Black, 3000>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Rgb16<64971,33514,829>, Black>, ColorSequence<1000, Black, Red>>>(),"Balance\nYellow"},
{ "grey", "tracks/medley1.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<AudioFlicker<Red,Rgb16<52226,1818,1818>>,Rgb16<65535,65535,17521>>,AudioFlicker<Red,White>,AudioFlicker<Red,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Red,Rgb16<65535,17521,17521>>,AudioFlicker<Red,White>,AudioFlicker<Red,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Red, Black, 3000>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Red, Black>, ColorSequence<1000, Black, Red>>>(),  "Grey\nRed"},
{ "Tano", "tracks/medley1.wav",
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<AudioFlicker<Rgb16<40982,40982,40982>,Rgb16<25982,25982,25982>>,Rgb16<65535,65535,17521>>,AudioFlicker<Rgb16<40982,40982,40982>,White>,AudioFlicker<Rgb16<40982,40982,40982>,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Rgb16<40982,40982,40982>,Rgb16<65535,17521,17521>>,AudioFlicker<Rgb16<40982,40982,40982>,White>,AudioFlicker<Rgb16<40982,40982,40982>,Rgb16<65535,62191,40982>>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Rgb16<40982,40982,40982>, Black, 3000>>>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, White, Black>, ColorSequence<1000, Black, Red>>>(), "Tano\nWhite"},
{ "TeensySF", "tracks/venus.wav",
&style_pov,
StyleNormalPtr<BLACK, BLACK, 300, 800>(),
StylePtr<InOutHelperX<SimpleClash<Lockup<Blast<Stripes<1,2500,BatteryLevelStyle,Black,Black>,Stripes<1,2500,BatteryLevelStyle,White,White>>,Stripes<1,2500,BatteryLevelStyle,White,White>,Stripes<1,2500,BatteryLevelStyle,Black,Black>>,White>,InOutFuncX<Int<300>,Int<300>>,Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Green, Black>, ColorSequence<1000, Black, Red>>>(), "POV"},
{ "TthCrstl", "tracks/mars.wav",
&style_charging,
StylePtr<Pulsing<BatteryLevelStyle, Black, 3000>>(),
StylePtr<Pulsing<Stripes<1,200,BatteryLevelStyle,Black,Black>, Black, 3000>>(),
StylePtr<Stripes<1, 0, ColorSequence<1000, Green, Black>, ColorSequence<1000, Black, Red>>>(),"Battery\nLevel"}
};

BladeConfig blades[] = {
 { 0, WS2811BladePtr<132, WS2813_800kHz | WS2811_GRB, bladePin, PowerPINS<bladePowerPin1,bladePowerPin2,bladePowerPin3> >(), //main blade
      WS2811BladePtr<1, WS2811_ACTUALLY_800kHz | WS2811_GRB, blade2Pin, PowerPINS<bladePowerPin6> >(),// crystal chamber
      WS2811BladePtr<3, WS2811_ACTUALLY_800kHz | WS2811_GRB, blade3Pin, PowerPINS<bladePowerPin5> >(),// Chassis Accent2s
      WS2811BladePtr<2, WS2811_ACTUALLY_800kHz | WS2811_GRB, blade4Pin, PowerPINS<bladePowerPin4> >(),// Arrow Lights
      CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
TouchButton PowerButton(BUTTON_POWER, powerButtonPin, 1800, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux2");
//Button PowerButton(BUTTON_POWER, auxPin, "pow");
//Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux");
#endif