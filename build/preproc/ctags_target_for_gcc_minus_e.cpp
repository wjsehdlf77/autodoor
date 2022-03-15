# 1 "c:\\workspace\\autodoor\\autodoor\\RFIDReader.cpp"
# 2 "c:\\workspace\\autodoor\\autodoor\\RFIDReader.cpp" 2


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
# 1 "c:\\workspace\\autodoor\\autodoor\\app.ino"
//적색LED 3, 녹색LED 4, buzzer 7, SERVO 5, rfid (sda 10~, sck 13, mosi 11, miso 12, rst 9), buzzer 8, button 6



RFIDReader rf(10, 9, 2, 5, 1, 3);

byte myId[] = {49, 181, 185, 26};


void setup()
{
    rf.init();
}

void loop()
{
    rf.equalid(myId, rf.uid.uidByte);
}
