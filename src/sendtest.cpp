// #include <Arduino.h>
// #include <Wire.h>

// #define I2C_ADDRESS     0x02

// void setup()
// {
//     Serial.begin(9600);
//     Wire.begin(I2C_ADDRESS);
// }

// int b=1;
// void loop()
// {
//     uint8_t buff[9]={0};
//     Wire.requestFrom(0x01, 9, 1);
//     Wire.readBytes(buff, 9);
//     Serial.print(buff[1]);
//     delay(500);
// }