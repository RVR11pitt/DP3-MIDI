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
  slidePotVal = analogRead(slidePot);

  // CALCULATE DIFFERENCE BETWEEN NEW VALUE AND LAST RECORDED VALUE //
  int slidePotValdiff = slidePotVal - lastSlidePotVal;
  
  // SEND MIDI MESSAGE //
  if (abs(slidePotValdiff) > diff)
  {
    writeMIDI(0xB1, 3, map(slidePotVal, 1023, 0, 0, 127));
    lastSlidePotVal = slidePotVal;
  }

  delay(20); // small delay further stabilizes sensor readings

}