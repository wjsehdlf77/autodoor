#line 1 "c:\\workspace\\autodoor\\autodoor\\RFIDReader.h"
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
    void open();
    void close();
    void reg();
    bool equalId();

};

#endif