/*
  Function: Converts analog input from potentiometers to MIDI signals

  Inputs:
    - NONE

  Outputs:
    - NONE

  NOTE: To negate variance in pot readings and overflow of MIDI messages,
         threshold was implemented. This stabilizes the pot readings and
         ensures communications are not flooded and program not slowed down. 

*/

void readPots() {
  
  int diff = 10; // difference amount

  // READ POTENTIOMETERS //
  slidePotVal1 = analogRead(slidePot1);
  slidePotVal2 = analogRead(slidePot2);

  // CALCULATE DIFFERENCE BETWEEN NEW VALUE AND LAST RECORDED VALUE //
  int slidePotValdiff1 = slidePotVal1 - lastSlidePotVal1;
  int slidePotValdiff2 = slidePotVal2 - lastSlidePotVal2;
  
  // SEND MIDI MESSAGE //
  if (abs(slidePotValdiff1) > diff)
  {
    writeMIDI(0xB1, 0, map(slidePotVal1, 1023, 0, 0, 127));
    lastSlidePotVal1 = slidePotVal1;
  }


  if (abs(slidePotValdiff2) > diff)
  {
    writeMIDI(0xB1, 1, map(slidePotVal2, 1023, 0, 0, 127));
    lastSlidePotVal2 = slidePotVal2;
  }

  delay(20); // small delay further stabilizes sensor readings

}