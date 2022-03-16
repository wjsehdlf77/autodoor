//적색LED 3, 녹색LED 4, buzzer 7, SERVO 5, rfid (sda 10~, sck 13, mosi 11, miso 12, rst 9), buzzer 8, button 6

#include <RFIDReader.h>
#include <SimpleTimer.h>


//rst, ss, servo, led1, led2, buzzer
RFIDReader rf(9, 10, 5, 4, 3, 7);
byte myId[] = {49, 181, 185, 26};
const int btn_pin = 6;
bool btn_state;


void main_sys() {
    btn_state = !digitalRead(btn_pin);
    if (btn_state) {
        rf.save();
        rf.led1_on();
        rf.led2_on();
        delay(5000);
        btn_state = false;
        rf.led1_off();
        rf.led2_off();
    }
    if (!btn_state) {
        rf.equalid(myId, rf.mfrc.uid.uidByte);
    }
}


void setup()
{
    rf.init();
    pinMode(btn_pin, INPUT_PULLUP);
}

void loop()
{
    main_sys();
}

