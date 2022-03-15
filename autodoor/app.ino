//적색LED 3, 녹색LED 4, buzzer 7, SERVO 5, rfid (sda 10~, sck 13, mosi 11, miso 12, rst 9), buzzer 8, button 6

#include "RFIDReader.h"

RFIDReader rf(9, 10, 2, 5, 1, 3);

byte myId[] = {49, 181, 185, 26};
byte otherID[] = mfrc.uid.uidByte;


void setup()
{
    rf.init();
}

void loop()
{
    rf.equalid(myId,);
}

