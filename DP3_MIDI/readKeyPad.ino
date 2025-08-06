/*
  Function: Reads keypad inputs

  Inputs:
    - NONE

  Outputs:
    - NONE

  NOTE: Runs on the keypad.h library. Structured with two case statements
        for handling turning the notes ON and OFF
*/

int kpc = 144; // the function of the keypad, 144 = Channel 1 Note on

void readKeyPad() {

  // KEYPAD //

  if (kpd.getKeys())  // supports up to ten simultaneous key presses
  {
    for (int i = 0; i < LIST_MAX; i++) // scan the whole key list
    {
      if ( kpd.key[i].stateChanged)   // find keys that have changed state
      {
        if (kpd.key[i].kstate == PRESSED) // sends MIDI on message when keys are pressed
        {
          switch (kpd.key[i].kchar) {
            case '1':
              writeMIDI(kpc, midC + 0, 127);
              break;
            case '2':
              writeMIDI(kpc, midC + 1, 127);
              break;
            case '3':
              writeMIDI(kpc, midC + 2, 127);
              break;
            case 'A':
              writeMIDI(kpc, midC + 3, 127);
              break;
            case '4':
              writeMIDI(kpc, midC + 4, 127);
              break;
            case '5':
              writeMIDI(kpc, midC + 5, 127);
              break;
            case '6':
              writeMIDI(kpc, midC + 6, 127);
              break;
            case 'B':
              writeMIDI(kpc, midC + 7, 127);
              break;
            case '7':
              writeMIDI(kpc, midC + 8, 127);
              break;
            case '8':
              writeMIDI(kpc, midC + 9, 127);
              break;
            case '9':
              writeMIDI(kpc, midC + 10, 127);
              break;
            case 'C':
              writeMIDI(kpc, midC + 11, 127);
              break;
            case '*':
              writeMIDI(kpc, midC + 12, 127);
              break;
            case '0':
              writeMIDI(kpc, midC + 13, 127);
              break;
            case '#':
              writeMIDI(kpc, midC + 14, 127);
              break;
            case 'D':
              writeMIDI(kpc, midC + 15, 127);

          }
        }

        if (kpd.key[i].kstate == RELEASED)  // sends MIDI off message when keys are released
        {
          switch (kpd.key[i].kchar) {
            case '1':
              writeMIDI(kpc - 16, midC + 0, 127);
              break;
            case '2':
              writeMIDI(kpc - 16, midC + 1, 127);
              break;
            case '3':
              writeMIDI(kpc - 16, midC + 2, 127);
              break;
            case 'A':
              writeMIDI(kpc - 16, midC + 3, 127);
              break;
            case '4':
              writeMIDI(kpc - 16, midC + 4, 127);
              break;
            case '5':
              writeMIDI(kpc - 16, midC + 5, 127);
              break;
            case '6':
              writeMIDI(kpc - 16, midC + 6, 127);
              break;
            case 'B':
              writeMIDI(kpc - 16, midC + 7, 127);
              break;
            case '7':
              writeMIDI(kpc - 16, midC + 8, 127);
              break;
            case '8':
              writeMIDI(kpc - 16, midC + 9, 127);
              break;
            case '9':
              writeMIDI(kpc - 16, midC + 10, 127);
              break;
            case 'C':
              writeMIDI(kpc - 16, midC + 11, 127);
              break;
            case '*':
              writeMIDI(kpc - 16, midC + 12, 127);
              break;
            case '0':
              writeMIDI(kpc - 16, midC + 13, 127);
              break;
            case '#':
              writeMIDI(kpc - 16, midC + 14, 127);
              break;
            case 'D':
              writeMIDI(kpc - 16, midC + 15, 127);

          }
        }
      }
    }
  }
}
