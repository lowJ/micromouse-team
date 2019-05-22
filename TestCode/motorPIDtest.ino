//motorPIDtest.ino
#include "PID.h"
int encoder_pin_1A = 17;
int encoder_pin_1B = 18;
int receiverF = 14; //
int receiverL = 15;
int receiverFront = 0; //
int receiverR = 16;
int emitterF = 0;
int emitterL = 1;
int emitterR = 2;
//int encoder_pin = 10;
const int ENCODER_STEPS = 360;
const float ENCODER_CIRC = 2.9*PI; //in cm
const float STEP_TO_CM = ENCODER_CIRC / ENCODER_STEPS;
const float CM_TO_STEP = 1 / STEP_TO_CM;
int a1_last;
int a1_current;
int pid_last_time = 0;
int pid_current_time = 0;
int sampleTime = 500; //in millis
double kp, ki, kd = 1;
PID pid_left = PID(0, 500, 0.5, 0.5, 0.5);
PID pid_right = PID(0, 500, 0.5, 0.5, 0.5);
volatile int encA = 0;

typedef struct{
  int motorEN, motorForward, motorReverse;
} motor;

motor FL = {0,0,0}; //format as {motorEN,motorForward,motorReverse}
motor FR = {0,0,0};
motor BL = {0,0,0};
motor BR = {0,0,0};
motor motors[4] = {FL,FR,BL,BR};



void motorSetup(motor m){
  pinMode(m.motorEN,OUTPUT);
  pinMode(m.motorForward,OUTPUT);
  pinMode(m.motorReverse,OUTPUT);
}

void motorMovement(motor m, int speed,int fv, int rv){
  //pid_left.setTarget(speed);
  analogWrite(m.motorEN,speed);
  digitalWrite(m.motorForward,fv);
  digitalWrite(m.motorReverse,rv);
}

void forwardTillRotation(int speed, float rotations){
  pid_left.setTarget(rotations);
  pid_right.setTarget(rotations);
  motorMovement(motors[0], speed,1,0);
  //motorMovement(motors[2], speed, 1, 0);
  while(encA < rotations * ENCODER_STEPS){
    int left_change = pid_left.compute();
    int right_change = pid_right.compute();
    if (left_change != 0 || right_change != 0)
    {
      motorMovement(motors[0], speed + left_change, 1, 0);
      motorMovement(motors[2], speed + right_change, 1, 0);
    }
    }
  }

void setupEncoder(){
  pinMode(encoder_pin_1A,INPUT);
  pinMode(encoder_pin_1B,INPUT);
}



void encoderOne(){
  a1_current = digitalRead(encoder_pin_1A);
  if (a1_last != a1_current){
   
    if (a1_current != digitalRead(encoder_pin_1B)){
      encOne++; //clockwise
    }
    else{
      encOne--; //counter-clockwise
    }
  }
  a1_last = a1_current;
}

void setupInterrupt(){
  //Serial.println(digitalPinToInterrupt(encoder_pin_A));
  attachInterrupt(digitalPinToInterrupt(encoder_pin_1A), encoderOne,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder_pin_1B), encoderOne,CHANGE);
  }

void setupIR()
{
    pinMode(receiverF,INPUT);
    pinMode(receiverL,INPUT);
    pinMode(receiverR,INPUT);

    pinMode(emitterF,OUTPUT);
    pinMode(emitterL,OUTPUT);
    pinMode(emitterR,OUTPUT);
    digitalWrite(emitterF,HIGH);
    digitalWrite(emitterL,HIGH);
    digitalWrite(emitterR,HIGH);
}

void setup()
{
    pid_left = PID(sampleTime, kp, ki, kd);
    pid_right = PID(sampleTime, kp, ki, kd);
    motorSetup(motors[0]);
    motorSetup(motors[2]);
    setupEncoder();
    setupInterrupt();
    setupIR();


}

void loop()
{
forwardTillRotation(150,5.0);
delay(2000);

}