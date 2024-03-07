#include <Arduino.h>
#include <Servo.h>
// #include <L298N.h>

#define SERVO_A_PIN 3
#define SERVO_B_PIN 6
#define SERVO_C_PIN 9

#define SERVO_TIME_MIN  500
#define SERVO_TIME_MAX  2500

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

Servo servoA;
Servo servoB;
Servo servoC;

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

void demo()
{
  Servo_Angles angles;
  Vector3 pos;

  delay(1000);
  for(int i=0;i<40;i+=1)
  {
    delay(50);

    pos.z=70+i;
    pos.y=0;
    pos.x=50;
    angles=set_pos(pos);

    servoA.write(angles.a);
    servoB.write(angles.b);
    servoC.write(angles.c); 
  }

  delay(1000);

  pos.z=50;
  pos.y=-50;
  pos.x=-50;
  angles=set_pos(pos);

  servoA.write(angles.a);
  servoB.write(angles.b);
  servoC.write(angles.c);  

  delay(1000);
  for(int i=0;i<40;i+=1)
  {
    delay(50);

    pos.z=70+i;
    pos.y=50;
    pos.x=0;
    angles=set_pos(pos);

    servoA.write(angles.a);
    servoB.write(angles.b);
    servoC.write(angles.c); 
  }


  delay(3000);

}

void setup() {
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
  
  demo();
  
}
