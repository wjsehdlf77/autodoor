# 1 "c:\\workspace\\autodoor\\autodoor\\app.ino"
# 2 "c:\\workspace\\autodoor\\autodoor\\app.ino" 2

//rst, ss, servo, led1, led2, buzzer
RFIDReader autodoor(9, 10, 5, 4, 3, 7);
byte myId[4];
const int btn_pin = 6;
bool btn_state;


void main_sys() {
    btn_state = !digitalRead(btn_pin);
    if (btn_state) {
        autodoor.save(btn_state);
        delay(5000);
        autodoor.lcd.clear();
    }
    else if (!btn_state) {
        autodoor.read(myId);
        autodoor.equalid(myId, autodoor.mfrc.uid.uidByte);
    }
}

void setup()
{
    autodoor.init();
    pinMode(btn_pin, 0x2);
}

void loop()
{
    main_sys();
}
