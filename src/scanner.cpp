// #include <Arduino.h>
// #include <Wire.h>

// #define I2C_ADDRESS     0x01

// uint8_t new_card=0;
// uint8_t UID[8];

// void I2C_got_request()
// {
//     Serial.println("Got request");
//     static int b;
//     b=!b;
//     digitalWrite(LED_BUILTIN, b);
    
//     Wire.write(new_card);
//     Wire.write(UID, sizeof(UID));
//     Serial.println("Answered\n");
    
// }

// void setup()
// {
//     Serial.begin(9600);
//     pinMode(LED_BUILTIN, OUTPUT);
//     Wire.begin(I2C_ADDRESS);
//     Wire.onRequest(I2C_got_request);

//     UID[0]=0x12;
//     new_card=0x1;
// }

// void loop()
// {
    
// }