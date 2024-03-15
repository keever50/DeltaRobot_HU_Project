#include <Arduino.h>
#include <Servo.h>
#include <L298N.h>
// #include <L298N.h>

#define SERVO_A_PIN 3
#define SERVO_B_PIN 6
#define SERVO_C_PIN 9

#define SERVO_TIME_MIN  500
#define SERVO_TIME_MAX  2500

const unsigned int IN1 = 12;
const unsigned int IN2 = 11;
const unsigned int EN = 10;

// Pin definition
// const unsigned int IN1 = 7;
// const unsigned int IN2 = 8;
// const unsigned int EN = 10;

// Create one motor instance
//L298N motor(EN, IN1, IN2);

// struct Position_s
// {
//   int x,y,z;
// };

L298N motor(EN, IN1, IN2);

Servo servoA;
Servo servoB;
Servo servoC;

struct Card
{
  float a;
};

typedef struct
{
  float x,y,z;
} Vector3;


typedef struct
{
  float a,b,c;
} Servo_Angles;

void get_angles(float* A, float* B, float* C, float angle, float movement)
{
  *A=movement*sin(angle);
  *B=movement*sin(angle+(2.0f/3.0f)*3.14);
  *C=movement*sin(angle-(2.0f/3.0f)*3.14);
}


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

void demo_pomp()
{
  
  motor.setSpeed(255);
  motor.forward();
  //delay(5000);
  //motor.forward();
  delay(1000);
  //motor.stop();
}

Vector3 ask_coords()
{
  Serial.setTimeout(999999);
  Vector3 vect;
  String str;
  Serial.println("Enter coords:\n");
  Serial.print("X: ");
  vect.x=atoi(Serial.readStringUntil('\n').c_str());
  Serial.print("Y: ");
  vect.y=atoi(Serial.readStringUntil('\n').c_str());
  Serial.print("Z: ");
  vect.z=atoi(Serial.readStringUntil('\n').c_str());
  Serial.println("Done\n");
  return vect;
}

void demo()
{
  

  Servo_Angles angles;
  Vector3 pos;

  delay(1000);
  for(int i=0;i<40;i+=1)
  {
    delay(100);

    pos.z=70+i;
    pos.y=0;
    pos.x=45;
    angles=set_pos(pos);

    servoA.write(angles.a);
    servoB.write(angles.b);
    servoC.write(angles.c); 
  }

  delay(1000);

  pos.z=50;
  pos.y=-10;
  pos.x=-10;
  angles=set_pos(pos);

  servoA.write(angles.a);
  servoB.write(angles.b);
  servoC.write(angles.c);  

  delay(1000);
  for(int i=0;i<40;i+=10)
  {
    delay(200);

    pos.z=70+i;
    pos.y=45;
    pos.x=0;
    angles=set_pos(pos);

    servoA.write(angles.a);
    servoB.write(angles.b);
    servoC.write(angles.c); 
  }


  delay(3000);

}


void demo2()
{
  Vector3 pos;
  pos.z=100;
  pos.y=-50;
  pos.x=0;
  Servo_Angles angles=set_pos(pos);

  servoA.write(angles.a);
  servoB.write(angles.b);
  servoC.write(angles.c);   

  delay(1000);
  pos.z=100;
  pos.y=50;
  pos.x=0;
  angles=set_pos(pos);

  servoA.write(angles.a);
  servoB.write(angles.b);
  servoC.write(angles.c);   

  delay(1000);
}

void demo3()
{
  while(true)
  {
    Vector3 vect = ask_coords();
    Servo_Angles angles = set_pos(vect);
    servoA.write(angles.a);
    servoB.write(angles.b);
    servoC.write(angles.c);   

    delay(1500); 
  }
}



void setup() {
  while(!Serial);

  Serial.begin(9600);
  

  Serial.println("Start");
  
  //motor.setSpeed(255);
  //motor.forward();

  servoA.attach(SERVO_A_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
  servoB.attach(SERVO_B_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
  servoC.attach(SERVO_C_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);

  Serial.println("Run");
}

void loop() {
  delay(100);
  //demo2();
  //demo_pomp();
  demo3();
  
}
