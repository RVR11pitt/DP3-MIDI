/*
  This is the main code for ECE 1895, Design Project 3. It contains the operating
  code for running a simple MIDI controller that interfaces with a digital audio
  workstation (DAW) through analog dials, sliders, buttons, and switches.

  PARTS:

*/

// KEYPAD //

#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // three columns
char keys[ROWS][COLS] = {  // keypad keys, 1-9, 0, S for star (asterisk) and P for pound (square)
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Mapping:
// Columns (pins 1–4): PD5 (D5), PD6 (D6), PD7 (D7), PB0 (D8)
// Rows    (pins 5–8): PB4 (D12), PB3 (D11), PB2 (D10), PB1 (D9)

byte colPins[COLS] = {5, 6, 7, 8};     // Columns C1–C4
byte rowPins[ROWS] = {12, 11, 10, 9};  // Rows R1–R4

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int midC = 60; // MIDI note value for middle C on a standard keyboard

// POTENTIOMETERS //

const int slidePot1 = A4;
const int slidePot2 = A5;

int slidePotVal1 = 0;
int slidePotVal2 = 0;

int lastSlidePotVal1 = 0;
int lastSlidePotVal2 = 0;

// ROTARY ENCODERS //

#define ENCODER_USE_INTERRUPTS
#include <Encoder.h>

Encoder enc1(2,A3);
Encoder enc2(3,A2);
long position1 = -999;
long position2 = -999;
int encVals[12] = {64, 64, 64, 64, 64, 64, 64, 64}; // set initial value of encoder to mid range of 0-127

// ROTARY SWITCH //
const int rotSwitch1 = 4;   // PD4
const int rotSwitch2 = A1;  // PC1
const int rotSwitch3 = A0;  // PC0
const int rotSwitch4 = 13;  // PB5
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
  readKeyPad();       // Read keypad

  // Extra delay to ensure no MIDI flooding
  delay(20);

}
