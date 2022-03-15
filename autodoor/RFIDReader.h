#ifndef RFIDREADER_H
#define RFIDREADER_H

#pragma once

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

class RFIDReader
{
protected:
    MFRC522 mfrc;
    int rst;
    int ss;
    int btn_pin;
    int servo_pin;
    int led1_pin;
    int led2_pin;
    bool no_btn;



public:
    RFIDReader(int rst, int ss, int btn_pin, int servo_pin, int led1_pin, int led2_pin);
    void init();
    void open(byte *id1, byte *id2);
    void close(byte *id1, byte *id2);
    void reg();

};

#endif