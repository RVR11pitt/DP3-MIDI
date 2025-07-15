/*
  This is the main code for ECE 1895, Design Project 3. It contains the operating
  code for running a simple MIDI controller that interfaces with a digital audio
  workstation (DAW) through analog dials, sliders, buttons, and switches.

  PARTS:

*/

// KEYPAD //

#include <Keypad.h>


// POTENTIOMETERS //

const int rotPot = A4;
const int slidePot = A5;

int rotPotVal = 0;
int slidePotVal = 0;

int lastRotPotVal = 0;
int lastSlidePotVal = 0;

// ROTARY ENCODERS //

#define ENDOER_DO_NOT_USE_INTERRUPTS
#include <Encoder.h>

Encoder enc1(A3,A2);
Encoder enc2(A1,A0);
long position1 = -999;
long position2 = -999;
int encVals[12] = {64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64}; // set initial value of encoder to mid range of 0-127

// ROTARY SWITCH //

const int rotSwitch1 = 2;
const int rotSwitch2 = 3;
const int rotSwitch3 = 4;
const int rotSwitch4 = 13;
int cVal = 1;

// DIAL //

void setup() {

  Serial.begin(9600); // enable serial communication

  pinMode(rotSwitch1, INPUT_PULLUP);
  pinMode(rotSwitch2, INPUT_PULLUP);
  pinMode(rotSwitch3, INPUT_PULLUP);
  pinMode(rotSwitch4, INPUT_PULLUP);

}

void loop() {

  readRotSwitch();    // Read rotary switch
  readEncoders();     // Read encoders
  readPots();         // Read potentiometers  

  // Extra delay to ensure no MIDI flooding
  delay(20);

}
