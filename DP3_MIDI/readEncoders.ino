/*
  Function: Reads encoder inputs

  Inputs:
    - NONE

  Outputs:
    - NONE

  NOTE: The values of the encoders are stored in an array to allow
        the values to be remembered when changing in between encoders
        using the rotary switch. The rotary switch sets the cVal value
        which determines which position in the array the value is stored
        at, and retrieved from.

        Values for the encoders are constrained to MIDI (0-127)

*/

void readEncoders() {

  long newPos1 = enc1.read(); // reads both encoders
  long newPos2 = enc2.read();

  if (newPos1 > position1) {  // increases encoder #1
    position1 = newPos1;
    encVals[cVal]++;
    encVals[cVal] = constrain(encVals[cVal], 0, 127);

    writeMIDI(0xB2, cVal, encVals[cVal]);
  }

  if (newPos1 < position1) {  // decreases encoder #1
    position1 = newPos1;
    encVals[cVal]--;
    encVals[cVal] = constrain(encVals[cVal], 0, 127);

    writeMIDI(0xB2, cVal, encVals[cVal]);
  }

  if (newPos2 > position2) {  // increases encoder #2
    position2 = newPos2;
    encVals[cVal + 1]++;
    encVals[cVal + 1] = constrain(encVals[cVal + 1], 0, 127);

    writeMIDI(0xB2, cVal + 1, encVals[cVal + 1]);
  }

  if (newPos2 < position2) {  // decreases encoder #2
    position2 = newPos2;
    encVals[cVal + 1]--;
    encVals[cVal + 1] = constrain(encVals[cVal + 1], 0, 127);

    writeMIDI(0xB2, cVal + 1, encVals[cVal + 1]);
  }

}