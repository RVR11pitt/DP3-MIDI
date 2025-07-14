/*
  This is the main code for ECE 1895, Design Project 3. It contains the operating
  code for running a simple MIDI controller that interfaces with a digital audio
  workstation (DAW) through analog dials and sliders, in additional to buttons
  and other switches for various purposes.



*/

const int slidePot = A3;

int slidePotVal = 0;

int lastSlidePotVal = 0;

void setup() {

  Serial.begin(9600); // enable serial communication

}

void loop() {



  readPots(); // Read potentiometers  

  // Extra delay to ensure no MIDI flooding
  delay(20);

}
