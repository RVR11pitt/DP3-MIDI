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
  rotPotVal = analogRead(rotPot);

  // CALCULATE DIFFERENCE BETWEEN NEW VALUE AND LAST RECORDED VALUE //
  int rotPotValdiff = rotPotVal - lastRotPotVal;
  
  // SEND MIDI MESSAGE //
  if (abs(rotPotValdiff) > diff)
  {
    writeMIDI(0xB1, 3, map(rotPotVal, 1023, 0, 0, 127));
    lastRotPotVal = rotPotVal;
  }

  delay(20); // small delay further stabilizes sensor readings

}