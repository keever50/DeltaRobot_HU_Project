#include <Arduino.h>
#include <Servo.h>

#define SERVO_A_PIN 3
#define SERVO_B_PIN 6
#define SERVO_C_PIN 9

#define SERVO_TIME_MIN  500
#define SERVO_TIME_MAX  2500

struct Position_s
{
  int x,y,z;
};

Servo servoA;
Servo servoB;
Servo servoC;

void get_angles(float* A, float* B, float* C, float angle, float movement)
{
  *A=movement*sin(angle);
  *B=movement*sin(angle+(3.0f/4.0f)*3.14);
  *C=movement*sin(angle-(3.0f/4.0f)*3.14);
}

void demo()
{
  static int state;
  float a;
  float A, B, C;
  switch(state)
  {
    case 0:
    {
      a=a+0.01;
      get_angles(&A,&B,&C, a, 40);
      servoA.write(90-A);
      servoB.write(90-B);
      servoC.write(90-C);
    }

    case 1:
    {

    }

    case 2:
    {

    }

  }
}

void setup() {

  Position_s pos;
  pos.x=1;
  pos.y=2;
  pos.z=3;

  servoA.attach(SERVO_A_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
  servoB.attach(SERVO_B_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
  servoC.attach(SERVO_C_PIN,SERVO_TIME_MIN, SERVO_TIME_MAX);
}

void loop() {
  delay(1);
  demo();
}
