#include "RFIDReader.h"


RFIDReader::RFIDReader(int rst, int ss, int btn_pin, int servo_pin, int led1_pin, int led2_pin)
                        : mfrc(ss, rst), btn_pin(btn_pin), servo_pin(servo_pin), led1_pin(led1_pin), led2_pin(led2_pin)
{
    no_btn = false;
}

void RFIDReader::init()
{
    SPI.begin();
    mfrc.PCD_Init();
    servo.attach(servo_pin);
}

void RFIDReader::equalid(byte *id1, byte *id2)
{
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial() ) {
        delay(500);
        return;

    for (int byte = 0; byte < 4; byte++) {
        if (id1[byte] != id2[byte]) {
            close();
        }
    }
    open();
    }
}


void RFIDReader::open()
{
    servo.write(180);
}

void RFIDReader::close()
{
    servo.write(0);
}

void RFIDReader::reg()
{
    
}


