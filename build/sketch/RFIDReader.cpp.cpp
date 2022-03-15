#include <Arduino.h>
#line 18 "c:\\workspace\\autodoor\\autodoor\\app.ino"
bool equalId(byte *id1, byte *id2);
#line 27 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void setup();
#line 35 "c:\\workspace\\autodoor\\autodoor\\app.ino"
void loop();
#line 0 "c:\\workspace\\autodoor\\autodoor\\app.ino"
#line 1 "c:\\workspace\\autodoor\\autodoor\\RFIDReader.cpp"
#include "RFIDReader.h"


RFIDReader::RFIDReader(int rst, int ss, int btn_pin, int servo_pin, int led1_pin, int led2_pin)
                        : rst(rst), ss(ss), btn_pin(btn_pin), servo_pin(servo_pin), led1_pin(led1_pin), led2_pin(led2_pin)
{
    
}

void RFIDReader::init()
{
    SPI.begin();
    MFRC.init();
}


void RFIDReader::open()
{
    
}

void RFIDReader::close()
{
    
}

void RFIDReader::reg()
{
    
}

bool RFIDReader::equalId()
{
    
}

#line 1 "c:\\workspace\\autodoor\\autodoor\\app.ino"
//적색LED 3, 녹색LED 4, buzzer 7, SERVO 5, rfid (sda 10~, sck 13, mosi 11, miso 12, rst 9), buzzer 8, button 6


#include <SPI.h>
#include <MFRC522.h>
#include <Buzzer.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);
Buzzer bizzer(3);
Servo servo;

byte myId[] = {49, 181, 185, 26};

bool equalId(byte *id1, byte *id2) {
    for (int byte = 0; byte < 4; byte++) {
        if (id1[byte] != id2[byte]) {
            return false;
        }
    }
    return true;
}

void setup()
{
    Serial.begin(115200);
    SPI.begin();
    mfrc.PCD_Init();
    servo.attach(5);
}

void loop()
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial() ) {
        delay(500);
        return;
    }
    
    if (equalId(myId, mfrc.uid.uidByte)) {
        Serial.println("Equal");
        bizzer.beep(100);
        servo.write(180);
        delay(5000);
        servo.write(0);

    }
    else {
        bizzer.beep(2000);
    }
}


