#include <Arduino.h>
#line 1 "c:\\workspace\\autodoor\\autodoor\\app.ino"
//적색LED 3, 녹색LED 4, buzzer 7, SERVO 5, rfid (sda 10~, sck 13, mosi 11, miso 12, rst 9), buzzer 8, button 6

#include <RFIDReader.h>


//rst, ss, servo, led1, led2, btn, buzzer
RFIDReader rf(9, 10, 5, 4, 3, 6, 7);

byte myId[4] = {49, 181, 185, 26};

#line 11 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void setup();
#line 16 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void loop();
#line 11 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void setup()
{
    rf.init();
}

void loop()
{
    rf.equalid(myId, rf.mfrc.uid.uidByte);

}


