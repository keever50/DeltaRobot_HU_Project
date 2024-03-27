#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Wire.h>
#include <Servo.h>

/*Servos*/
#define SERVO_A_PIN 30
#define SERVO_B_PIN 31
#define SERVO_C_PIN 32

#define SERVO_TIME_MIN  500
#define SERVO_TIME_MAX  2500
Servo servoA;
Servo servoB;
Servo servoC;

/*Scanner*/
#define RC522_CS    53
#define RC522_RST   3
MFRC522 rfid(RC522_CS, RC522_RST);

#define CARDLIST_UID_MAX_LEN    4
#define CARDLIST_UID_ENTRIES    3
char card_ids[CARDLIST_UID_ENTRIES][CARDLIST_UID_MAX_LEN]=
{
    {(char)0x53,(char)0x33,(char)0xA5,(char)0x91},
    {0,0,0,0},
    {0,0,0,0}
};

typedef struct
{
  float x,y,z;
} Vector3;

typedef struct
{
  float a,b,c;
} Servo_Angles;

const Vector3 coords[10]=
{
    {-15,30,100},
    {8,40,100},
    {-10,15,105},
    {12,25,100},
    {-5,0,105},
    {20,10,105},
    {0,-12,105},
    {25,-3,103},
    {8,-25,102},
    {31,-15,102}

};


Servo_Angles set_pos( Vector3 pos )
{
  Servo_Angles servo={0};

  servo.c+=sin(0)*pos.x;
  servo.a+=sin((2.0F/3.0F)*3.14F)*pos.x;
  servo.b+=sin(-(2.0F/3.0F)*3.14F)*pos.x;

  servo.c+=cos(0)*pos.y;
  servo.a+=cos((2.0F/3.0F)*3.14F)*pos.y;
  servo.b+=cos(-(2.0F/3.0F)*3.14F)*pos.y;  

  servo.c+=pos.z;
  servo.a+=pos.z;
  servo.b+=pos.z;

  return servo;
}

void set_servos(Servo_Angles angs)
{
    servoA.write(angs.a);
    servoB.write(angs.b);
    servoC.write(angs.c);
}

void move_to(Vector3 pos)
{
    Servo_Angles angs = set_pos({0,0,150});
    Serial.println("Going to: ");
    Serial.println(pos.x);
    Serial.println(pos.y);
    Serial.println(pos.z);
    delay(2000);



}

/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/*Returns -1 on no match*/
int find_card()
{
    printHex(rfid.uid.uidByte, rfid.uid.size);
    for(int entry_i=0;entry_i<CARDLIST_UID_ENTRIES;entry_i++)
    {
        int comp = strcmp(card_ids[entry_i], (const char*)rfid.uid.uidByte);
        if(comp!=0) continue;

        Serial.println("MATCH");
        return entry_i;
    }

    return -1;
}

int scan_card()
{
    return 0;
}

#define STATE_INIT  -1
#define STATE_IDLE  0
#define STATE_READ  1
struct 
{
    int state=STATE_INIT;
}
bot_sm_vars;

void bot_statemachine()
{
    static unsigned long lasttime;

    switch(bot_sm_vars.state)
    {
        case STATE_INIT:
        {
            Serial.println("Initializing RFID");
            pinMode(RC522_RST, OUTPUT);
            pinMode(RC522_CS, OUTPUT);
            rfid.PCD_Init(); // Init MFRC522

            Serial.println("Now scanning for cards...");
            bot_sm_vars.state = STATE_IDLE;
            break;
        }

        case STATE_IDLE:
        {
            /*Check if card is present*/
            if(!rfid.PICC_IsNewCardPresent()) break;
            Serial.println("Card detected");
            bot_sm_vars.state = STATE_READ;
            lasttime=millis();
            break;
        }

        case STATE_READ:
        {
            /*Timeout*/
            if(millis()-lasttime>1000)
            {
                Serial.println("Timeout");
                bot_sm_vars.state=STATE_IDLE;
                break;
            }

            /*Try to read card*/
            if(!rfid.PICC_ReadCardSerial()) break;
            Serial.println("Card read");
            
            /*Check type*/
            if(rfid.PICC_GetType(rfid.uid.sak) != MFRC522::PICC_TYPE_MIFARE_1K)
            {
                Serial.println("Incorrect card type");
                bot_sm_vars.state=STATE_IDLE;
                break;
            }          

            Serial.println("READING");
            int ID = find_card();
            /*Card not found*/
            if(ID==-1) 
            {
                Serial.println("Card not found in database");
                bot_sm_vars.state=STATE_IDLE;
                break;
            }
            /*Card found*/
            move_to(coords[ID]);


            bot_sm_vars.state=STATE_IDLE;
            break;
        }
    }
}

void setup()
{
    Serial.begin(9600);
    while(!Serial);
    SPI.begin(); // Init SPI bus
        
  servoA.attach(SERVO_A_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
  servoB.attach(SERVO_B_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
  servoC.attach(SERVO_C_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
}

void loop()
{
    bot_statemachine();
    delay(5);
}