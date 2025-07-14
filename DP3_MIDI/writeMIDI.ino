/*
  Function: Takes 3 bytes of data and writes them to serial as one MIDI message

  Inputs:
    - status: first byte containing message type and channel number
    - data1: second byte containing note number or controller number
    - data2: third byte containing velocity/controller value

  Outputs:
    - NONE

  Source for determining MIDI signal structures taken from:
    - https://www.midi.org/specifications-old/item/table-2-expanded-messages-list-status-bytes
*/

void writeMIDI(byte status, byte data1, byte data2)
{
  Serial.write(status);
  Serial.write(data1 & 0x7F);
  Serial.write(data2 & 0x7F);
}