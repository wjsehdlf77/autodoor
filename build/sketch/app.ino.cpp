#include <Arduino.h>
#line 1 "c:\\workspace\\autodoor\\autodoor\\app.ino"
#include <RFIDReader.h>

//rst, ss, servo, led1, led2, buzzer
RFIDReader autodoor(9, 10, 5, 4, 3, 7);
byte myId[4];
const int btn_pin = 6;
bool btn_state;



#line 11 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void main_sys();
#line 22 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void setup();
#line 28 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void loop();
#line 11 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void main_sys() {
    btn_state = !digitalRead(btn_pin);
    if (btn_state) {
        autodoor.save(btn_state);       
    }
    else if (!btn_state) {
        autodoor.read(myId);
        autodoor.equalid(myId, autodoor.mfrc.uid.uidByte);
    }
}

void setup()
{
    autodoor.init();
    pinMode(btn_pin, INPUT_PULLUP);
}

void loop()
{
    main_sys();
}


