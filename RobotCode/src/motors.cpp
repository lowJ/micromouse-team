// methods to move the robot around

#include <Arduino.h>
#include "../inc/motors.hpp"
#include "../inc/marcros.hpp"

// Sets up a motor's pins
void motorSetup(motor m)
{
    pinMode(m.motorEN,INPUT);
    pinMode(m.motorForward,INPUT);
    pinMode(m.motorReverse,INPUT);
}

// Moves a motor with a speed <speed>
// <fv> of 1 with <rv> of 0 moves motor forward
// <rv> of 1 with <fv> of 0 moves motor backward
void motorMovement(motor m, int enable,int f_speed, int r_speed)
{
    digitalWrite(m.motorEN, enable);
    analogWrite(m.motorForward, f_speed);
    analogWrite(m.motorReverse, r_speed);
}
void encoderSetup(motor m)
{
  pinMode(m.encP1,INPUT);
  pinMode(m.encP2,INPUT);
  enc_last = digitalRead(m.encP1);
}

void interruptSetup(motor m)
{
    attachInterrupt(m.encP1, encoderTick, CHANGE);
    attachInterrupt(m.encP2, encoderTick, CHANGE);
}

void encoderTick()
{
  //Serial.println("Encoder call");
  int incr;
  if (reverse) {incr = -1;}
  else {incr = 1;}
  enc_current = digitalRead(this->encP1);

  if (enc_last != enc_current){
   
    if (enc_current != digitalRead(this->encP2)){
      enc_value += incr; //forward (clockwise for the left(?) motor)
    }
    else{
      enc_value -= incr; //backward (counter-clockwise for the left(?) motor)
    }
  }
  //Serial.println(enc_value);
  //Serial.println("  ");
  enc_last = enc_current;
}

// Stops the robot when <encoderVal> > <threshold>
void runTillThresholdForward(int& encoderVal, int threshold)
{
    double left_change;
    double right_change;
    double left_new_speed = speed;
    double right_new_speed = speed;
    int initEnc = encoderVal
    while(encoderVal-initEnc < threshold)
    {
        
        continue;
    }
    off();
}

// Stops the robot when -<encoderVal> > <threshold>
void runTillThresholdBackward(int& encoderVal, int threshold)
{
    int initEnc = encoderVal
    while(-encoderVal+initEnc < threshold)
    {
        continue;
    }
    off();
}

// Moves robot forward with speed <speed>
void forward(int speed)
{
    for (int i = 0; i <= 1; i++)
    {
        motorMovement(motors[i],1,speed,0);
    }
}

// Moves robot forward at speed <speed> for <rotations> amount of wheel revolutions
void forwardTillDistance(int speed, float distance)
{
    forward(speed);
    runTillThresholdForward(FL_enc.ticks,static_cast<int>(CM_TO_STEP * distance));
}

// Moves robot backward with speed <speed>
void reverse(int speed)
{
    for (int i = 0; i <= 1; i++)
    {
        motorMovement(motors[i],1,0,speed);
    }
}

// Moves robot forward at speed <speed> for <rotations> amount of wheel revolutions
void reverseTillDistance(int speed, float distance)
{
    reverse(speed);
    runTillThresholdBackward(FL_enc.ticks,static_cast<int>(CM_TO_STEP * distance));
}

// Turns robot left, counterclockwise, at speed <speed>
void turnLeft(int speed, int degrees)
{
    motorMovement(FL,1,0,speed);
    motorMovement(FR,1,speed,0);

    runTillThresholdForward(FR_enc.ticks,static_cast<int>(DEG_TO_STEP * degrees));
}

// Turns robot right, clockwise, at speed <speed>
void turnRight(int speed,int degrees)
{
    motorMovement(FL,1,speed,0);
    motorMovement(FR,1,0,speed);

    runTillThresholdForward(FL_enc.ticks,static_cast<int>(DEG_TO_STEP * degrees));
}

// Stops all robot motors
void off()
{
    for (int i = 0; i <= 1; i++)
    {
        motorMovement(motors[i],0,0,0);
    }
}