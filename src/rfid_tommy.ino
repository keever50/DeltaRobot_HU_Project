
// #include <SPI.h>
// #include <MFRC522.h>
// #include <Wire.h>

// #define SS_PIN 10
// #define RST_PIN 9

// /* wat is de id van iedere chip? */
// int CHIP1[4] = { 132, 144, 108, 167 };
// int CHIP2[4] = { 132, 144, 108, 167 };
// int CHIP3[4] = { 132, 144, 108, 167 };
// int CHIP4[4] = { 132, 144, 108, 167 };gjdsgnjsdnjglkdsnlkagdnjkgnjldajgnfjkddfggggggggggg
// int CHIP5[4] = { 132, 144, 108, 167 };
// int CHIP6[4] = { 132, 144, 108, 167 };
// int CHIP7[4] = { 132, 144, 108, 167 };
// int CHIP8[4] = { 132, 144, 108, 167 };
// int CHIP9[4] = { 132, 144, 108, 167 };
// int CHIP10[4] = { 132, 144, 108, 167 };

// int beweegnaar;

// /*gejat van example*/

// MFRC522 rfid(SS_PIN, RST_PIN);

// MFRC522::MIFARE_Key key;

// byte nuidPICC[4];

// void setup() {
//   Wire.begin();

//   Serial.begin(9600);
//   SPI.begin();      // Init SPI bus
//   rfid.PCD_Init();  // Init MFRC522

//   for (byte i = 0; i < 6; i++) {
//     key.keyByte[i] = 0xFF;
//   }

//   Serial.println(F("Please scan your UAC badge"));
//   Serial.print(F("Tip: Have you filled out your UAC accidental death and dismemberment form yet? See Jessica in human resources for assistance"));
//   printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
//   Serial.println(F(" _   _"));
//   Serial.println(F("| |_| |__   ___ _ __ __ _ _ __   ___  ___"));
//   Serial.println(F("| __| '_ \ / _ \ '__/ _` | '_ \ / _ \/ __|"));
//   Serial.println(F("| |_| | | |  __/ | | (_| | | | | (_) \__ "));
//   Serial.println(F(" \__|_| |_|\___|_|  \__,_|_| |_|\___/|___/"));
//   Serial.println(F(""));
// }

// void loop() {

//   // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
//   if (!rfid.PICC_IsNewCardPresent())
//     return;

//   // Verify if the NUID has been readed
//   if (!rfid.PICC_ReadCardSerial())
//     return;

//   Serial.print(F("PICC type: "));
//   MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
//   Serial.println(rfid.PICC_GetTypeName(piccType));

//   // Check is the PICC of Classic MIFARE type
//   if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && piccType != MFRC522::PICC_TYPE_MIFARE_1K && piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
//     Serial.println(F("Verkeerde soort tag. Luca is een mongool."));
//     return;
//   }

//   if (rfid.uid.uidByte[0] != nuidPICC[0] || rfid.uid.uidByte[1] != nuidPICC[1] || rfid.uid.uidByte[2] != nuidPICC[2] || rfid.uid.uidByte[3] != nuidPICC[3]) {
//     Serial.println(F("Er is een tag gedetecteerd! Joepie!"));
//     Serial.println(F("Het ID is:"));

//     // Store NUID into nuidPICC array
//     for (byte i = 0; i < 4; i++) {
//       nuidPICC[i] = rfid.uid.uidByte[i];
//     }

//     printDec(rfid.uid.uidByte, rfid.uid.size);
//     Serial.println();

//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⢀⣴⠟⠉⠀⠀⠀⠈⠻⣦⡀⠀⠀⠀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣀⢀⣾⠿⠻⢶⣄⠀⠀⣠⣶⡿⠶⣄⣠⣾⣿⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⢻⣿⣿⡿⣿⠿⣿⡿⢼⣿⣿⡿⣿⣎⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⠉⠛⢛⣛⡉⠀⠀⠙⠛⠻⠛⠑⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣀⣟⠻⢦⣀⡀⠀⠀⠀⠀⣀⡈⠻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⡿⠉⡇⠀⠀⠛⠛⠛⠋⠉⠉⠀⠀⠀⠹⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡟⠀⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠈⠑⠪⠷⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⣿⣦⣼⠛⢦⣤⣄⡀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠑⠢⡀⠀⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠀⢀⣠⠴⠲⠖⠛⠻⣿⡿⠛⠉⠉⠻⠷⣦⣽⠿⠿⠒⠚⠋⠉⠁⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢦⠀⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⠀⢀⣾⠛⠁⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢣⠀⠀⠀"));
//     Serial.println(F("⠀⠀⠀⠀⣰⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀"));
//     Serial.println(F("⠀⠀⠀⣰⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣧⣄⠀⠀⠀⠀⠀⠀⢳⡀⠀"));
//     Serial.println(F("⠀⠀⠀⣿⡾⢿⣀⢀⣀⣦⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⣫⣿⡿⠟⠻⠶⠀⠀⠀⠀⠀⢳⠀"));
//     Serial.println(F("⠀⠀⢀⣿⣧⡾⣿⣿⣿⣿⣿⡷⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢿⣿⣧⠀⡀⠀⢀⣀⣀⢒⣤⣶⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇"));
//     Serial.println(F("⠀⣸⠃⠀⠀⢸⠃⠀⠀⢸⣿⣿⣿⣿⣿⣿⣷⣾⣿⣿⠟⡉⠀⠀⠀⠈⠙⠛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇"));
//     Serial.println(F("⠀⣿⠀⠀⢀⡏⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠛⠉⠁⠀⠀⠀⠀⠀⠉⠠⠿⠟⠻⠟⠋⠉⢿⣿⣦⡀⢰⡀⠀⠀⠀⠀⠀⠀⠁"));
//     Serial.println(F("⢀⣿⡆⢀⡾⠀⠀⠀⠀⣾⠏⢿⣿⣿⣿⣯⣙⢷⡄⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣿⣻⢿⣷⣀⣷⣄⠀⠀⠀⠀⢸⠀"));
//     Serial.println(F("⢸⠃⠠⣼⠃⠀⠀⣠⣾⡟⠀⠈⢿⣿⡿⠿⣿⣿⡿⠿⠿⠿⠷⣄⠈⠿⠛⠻⠶⢶⣄⣀⣀⡠⠈⢛⡿⠃⠈⢿⣿⣿⡿⠀⠀⠀⠀⠀⡀"));
//     Serial.println(F("⠟⠀⠀⢻⣶⣶⣾⣿⡟⠁⠀⠀⢸⣿⢅⠀⠈⣿⡇⠀⠀⠀⠀⠀⣷⠂⠀⠀⠀⠀⠐⠋⠉⠉⠀⢸⠁⠀⠀⠀⢻⣿⠛⠀⠀⠀⠀⢀⠇"));
//     Serial.println(F("⠀⠀⠀⠀⠹⣿⣿⠋⠀⠀⠀⠀⢸⣧⠀⠰⡀⢸⣷⣤⣤⡄⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡆⠀⠀⠀⠀⡾⠀⠀⠀⠀⠀⠀⢼⡇"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠙⢻⠄⠀⠀⠀⠀⣿⠉⠀⠀⠈⠓⢯⡉⠉⠉⢱⣶⠏⠙⠛⠚⠁⠀⠀⠀⠀⠀⣼⠇⠀⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀⡇"));
//     Serial.println(F("⠀⠀⠀⠀⠀⠀⠻⠄⠀⠀⠀⢀⣿⠀⢠⡄⠀⠀⠀⣁⠁⡀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⢀⣐⡟⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⢠⡇"));

//     if (rfid.uid.uidByte[0] != CHIP1[0] || rfid.uid.uidByte[1] != CHIP1[1] || rfid.uid.uidByte[2] != CHIP1[2] || rfid.uid.uidByte[3] != CHIP1[3]) {
//       beweegnaar = 1;
//     }
//     if (rfid.uid.uidByte[0] != CHIP2[0] || rfid.uid.uidByte[1] != CHIP2[1] || rfid.uid.uidByte[2] != CHIP2[2] || rfid.uid.uidByte[3] != CHIP2[3]) {
//       beweegnaar = 2;
//     }
//     if (rfid.uid.uidByte[0] != CHIP3[0] || rfid.uid.uidByte[1] != CHIP3[1] || rfid.uid.uidByte[2] != CHIP3[2] || rfid.uid.uidByte[3] != CHIP3[3]) {
//       beweegnaar = 3;
//     }
//     if (rfid.uid.uidByte[0] != CHIP4[0] || rfid.uid.uidByte[1] != CHIP4[1] || rfid.uid.uidByte[2] != CHIP4[2] || rfid.uid.uidByte[3] != CHIP4[3]) {
//       beweegnaar = 4;
//     }
//     if (rfid.uid.uidByte[0] != CHIP5[0] || rfid.uid.uidByte[1] != CHIP5[1] || rfid.uid.uidByte[2] != CHIP5[2] || rfid.uid.uidByte[3] != CHIP5[3]) {
//       beweegnaar = 5;
//     }
//     if (rfid.uid.uidByte[0] != CHIP6[0] || rfid.uid.uidByte[1] != CHIP6[1] || rfid.uid.uidByte[2] != CHIP6[2] || rfid.uid.uidByte[3] != CHIP6[3]) {
//       beweegnaar = 6;
//     }
//     if (rfid.uid.uidByte[0] != CHIP7[0] || rfid.uid.uidByte[1] != CHIP7[1] || rfid.uid.uidByte[2] != CHIP7[2] || rfid.uid.uidByte[3] != CHIP7[3]) {
//       beweegnaar = 7;
//     }
//     if (rfid.uid.uidByte[0] != CHIP8[0] || rfid.uid.uidByte[1] != CHIP8[1] || rfid.uid.uidByte[2] != CHIP8[2] || rfid.uid.uidByte[3] != CHIP8[3]) {
//       beweegnaar = 8;
//     }
//     if (rfid.uid.uidByte[0] != CHIP9[0] || rfid.uid.uidByte[1] != CHIP9[1] || rfid.uid.uidByte[2] != CHIP9[2] || rfid.uid.uidByte[3] != CHIP9[3]) {
//       beweegnaar = 9;
//     }
//     if (rfid.uid.uidByte[0] != CHIP10[0] || rfid.uid.uidByte[1] != CHIP10[1] || rfid.uid.uidByte[2] != CHIP10[2] || rfid.uid.uidByte[3] != CHIP10[3]) {
//       beweegnaar = 10;
//     } else Serial.print("ERROR: chip is niet een van de 10");
//     return;

//     Serial.print(F("Plaats nu een medisch goedgekeurde beker in vakje: "));
//     Serial.println((beweegnaar));

//     Wire.beginTransmission(0x55);  // WELK ADRES??
//     Wire.write((beweegnaar));
//     Wire.endTransmission();

//     beweegnaar = 0;

//   } else Serial.println(F("Card read previously."));


//   // Halt PICC
//   rfid.PICC_HaltA();

//   // Stop encryption on PCD
//   rfid.PCD_StopCrypto1();
// }


// /**
//  * Helper routine to dump a byte array as hex values to Serial. 
//  */
// void printHex(byte* buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
//     Serial.print(buffer[i], HEX);
//   }
// }

// /**
//  * Helper routine to dump a byte array as dec values to Serial.
//  */
// void printDec(byte* buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(' ');
//     Serial.print(buffer[i], DEC);
//   }
// }
