#include ".\\inc\\PID.hpp"
#include ".\\inc\\marcros.hpp"
//
//
//    MOVEMENT CODE   //
//
int encoder_pin_1A = 17;
int encoder_pin_1B = 18;
int encoder_pin_2A = 19;
int encoder_pin_2B = 20;
/*
int receiverF = 14;
int receiverL = 15;
int receiverR = 16;
int emitterF = 0;
int emitterL = 1;
int emitterR = 2;
*/
/*
//Alternate pin numbers might be necessary
const int ENCODER_STEPS = 360;
const float ENCODER_CIRC = 2.9*PI; //in cm
const float STEP_TO_CM = ENCODER_CIRC / ENCODER_STEPS;
const float CM_TO_STEP = 1 / STEP_TO_CM;
*/
volatile int encOne = 0;
volatile int encTwo = 0;
int a1_last;
int a1_current;
int a2_last;
int a2_current;
/*
typedef struct{
  int motorEN, motorForward, motorReverse;
} motor;
*/
double kp = 3;
double ki = 0.3;
double kd = 0.1;
PID pid_left = PID(0, 1000, kp, ki, kd);
PID pid_right = PID(0, 1000, kp, ki, kd);
//
/*
motor FL = {7,4,3}; //format as {motorEN,motorForward,motorReverse}
motor FR = {0,0,0};
motor BL = {8,6,5};
motor BR = {0,0,0};
motor motors[4] = {FL,FR,BL,BR};
*/

void motorSetup(motor m){
  pinMode(m.motorEN,INPUT);
  pinMode(m.motorForward,INPUT);
  pinMode(m.motorReverse,INPUT);
}


void motorMovement(motor m, int enable,int f_speed, int r_speed){
  digitalWrite(m.motorEN, enable);
  analogWrite(m.motorForward, f_speed);
  analogWrite(m.motorReverse, r_speed);
}

/*
void forward(int speed){
  for (int i = 0; i <= 3; i++){
    motorMovement(motors[i],speed,1,0);
  }
}
*/
void forwardTillRotation(int speed, double rotations){
  motor m_left = motors[0];
  motor m_right = motors[1];
  double left_change;
  double right_change;
  double left_new_speed = speed;
  double right_new_speed = speed;
  
  pid_left.setTarget(2.0);
  pid_right.setTarget(2.0);
  motorMovement(m_left, 1, speed, 0);
  motorMovement(m_right, 1, speed, 0);
  
  while(abs(encOne) < rotations * ENCODER_STEPS){
     
     left_change = pid_left.compute(encOne/360.0);
     right_change = pid_right.compute(encTwo/360.0);
    if (left_change != 0 || right_change != 0)
    {
      left_new_speed += left_change;
      right_new_speed += right_change;
      motorMovement(m_left, 0, left_new_speed, 0);
      motorMovement(m_right, 0, right_new_speed, 0);
    }
    
    }
  digitalWrite(m_left.motorEN,0);
  analogWrite(m_left.motorForward,0);
  digitalWrite(m_right.motorEN,0);
  analogWrite(m_right.motorForward,0);
  /*
  Serial.print("Motor 1 rotations:");
  Serial.println(encOne/360.0);
  Serial.print("Motor 2 rotations:");
  Serial.println(encTwo/360.0);
  */encOne = 0;
  encTwo = 0;
  }



void reverseTillRotation(int speed, float rotations){
  digitalWrite(motors[0].motorEN,1);
  analogWrite(motors[0].motorForward,0);
  analogWrite(motors[0].motorReverse,speed);
  //include second motor later
  while(abs(encOne) < rotations * ENCODER_STEPS){
    
  }
  digitalWrite(motors[0].motorEN,0);
  analogWrite(motors[0].motorReverse,0);
  encOne = 0;
}



void calcRotationsPerSecond(int speed)
{
  int current_time = millis();
  int base_time = millis();
  encOne = 0;
  encTwo = 0;
  digitalWrite(motors[0].motorEN,1);
  digitalWrite(motors[1].motorEN,1);
  analogWrite(motors[0].motorForward,speed);
  analogWrite(motors[1].motorForward,speed);
  analogWrite(motors[0].motorReverse,0);
  analogWrite(motors[1].motorReverse,0);
  while (current_time - base_time < 10000)
  {
    current_time = millis();
  }
  digitalWrite(motors[0].motorEN,0);
  digitalWrite(motors[1].motorEN,0);
  analogWrite(motors[0].motorForward,0);
  analogWrite(motors[1].motorForward,0);
  
  float rotations_one = float(encOne)/360.0;
  float rot_per_sec_one = rotations_one/float(current_time/1000);
  float rotations_two = float(encTwo)/360.0;
  float rot_per_sec_two = rotations_two/float(current_time/1000);
  
  Serial.print("motorForward pulse width value set:");
  Serial.println(speed);
  Serial.print("Rotations done (Motor left):");
  Serial.println(rotations_one);
  Serial.print("Rotations per second (Motor left):");
  Serial.println(rot_per_sec_one);
  Serial.print("RPS per pulse width value (Motor left):");
  Serial.println(rot_per_sec_one/float(speed));
  Serial.print("Rotations done (Motor right):");
  Serial.println(rotations_two);
  Serial.print("Rotations per second (Motor right):");
  Serial.println(rot_per_sec_two);
  Serial.print("RPS per pulse width value (Motor right):");
  Serial.println(rot_per_sec_two/float(speed));
  
  delay(10000);
}
/*
void reverse(int speed){
  for (int i = 0; i <= 3; i++){
    motorMovement(motors[i],speed,0,1);
  }
}

void turnLeft(int speed){
  motorMovement(FL,speed,0,1);
  motorMovement(BL,speed,0,1);
  motorMovement(FR,speed,1,0);
  motorMovement(BR,speed,1,0);
}

void turnRight(int speed){
  motorMovement(FL,speed,1,0);
  motorMovement(BL,speed,1,0);
  motorMovement(FR,speed,0,1);
  motorMovement(BR,speed,0,1);
}

void off(){
  for (int i = 0; i <= 3; i++){
    motorMovement(motors[i],0,0,0);
  }
}

bool detectWall(int reciever, int threshold){
  return threshold <= analogRead(reciever);
}
*/

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

//
//
//    ENCODER CODE    //
//

void setupEncoder(){
  pinMode(encoder_pin_1A,INPUT);
  pinMode(encoder_pin_1B,INPUT);
  pinMode(encoder_pin_2A,INPUT);
  pinMode(encoder_pin_2B,INPUT);
}



void encoderOne(){
  //Serial.println("EncoderOne call");
  
  a1_current = digitalRead(encoder_pin_1A);
  //Serial.println(a1_last);
  //Serial.println(a1_current);
  if (a1_last != a1_current){
   
    if (a1_current != digitalRead(encoder_pin_1B)){
      encOne++; //clockwise
    }
    else{
      encOne--; //counter-clockwise
    }
  }
  //Serial.println(encOne);
  //Serial.println("  ");
  a1_last = a1_current;
}

void encoderTwo(){
  //Serial.println("EncoderTwo call");
 
  a2_current = digitalRead(encoder_pin_2A);
  //Serial.println(a2_last);
  //Serial.println(a2_current);
  if (a2_last != a2_current){
   
    if (a2_current != digitalRead(encoder_pin_2B)){
      encTwo++; //clockwise
    }
    else{
      encTwo--; //counter-clockwise
    }
  }
  //Serial.println(encTwo);
  //Serial.println("  ");
  a2_last = a2_current;
}


void setupInterrupt(){
  //Serial.println(digitalPinToInterrupt(encoder_pin_A));
  attachInterrupt(encoder_pin_1A, encoderOne,CHANGE);
  attachInterrupt(encoder_pin_1B, encoderOne,CHANGE);
  attachInterrupt(encoder_pin_2A, encoderTwo, CHANGE);
  attachInterrupt(encoder_pin_2B, encoderTwo, CHANGE);
  }

void motorSpeedTest(){
  motor m = motors[0];
  int motor_speed = 0;
  int current_time = 0;
  int prev_time = 0;
  Serial.println(m.motorForward);
  digitalWrite(m.motorEN,1);
  analogWrite(m.motorForward, motor_speed);
  analogWrite(m.motorReverse, 0);
  //int i = 0;
  while (motor_speed < 246)
  {
    current_time = millis();
    if (current_time - prev_time > 500){
       analogWrite(m.motorForward, motor_speed);
       motor_speed += 10;
       prev_time = current_time;
    }
  }
 analogWrite(m.motorForward, 0);
  
}
//
//
//    SETUP AND LOOP    //
//
void setup() {
  /*
  for (int i = 0; i <= 3; i++){
    motorSetup(motors[i]);
  }
  */
  Serial.begin(9600);
  
  motorSetup(motors[0]);
  
  motorSetup(motors[1]);
  
  
  setupEncoder();
  setupInterrupt();
  //pinMode(receiverFront,INPUT);
  a1_last = digitalRead(encoder_pin_1A);
  a2_last = digitalRead(encoder_pin_2A);
  //setupIR();
  encOne = 0;
  encTwo = 0;
}

void loop() {
  Serial.println("Hi");
  // put your main code here, to run repeatedly:
  /*
  Serial.println(analogRead(motors[0].motorEN));
  Serial.print("Emitter F:");
  Serial.println(analogRead(receiverF));
  Serial.print("Emitter L:");
  Serial.println(analogRead(receiverL));
  Serial.print("Emitter R:");
  Serial.println(analogRead(receiverR));
  delay(2000);
  */
  /*
  for (int i = 0; i < 100; i+=10)
  {
    calcRotationsPerSecond(100+i);
    Serial.println(" ");
  }
  */
  //motorSpeedTest();
  forwardTillRotation(125,10.0);
  delay(5000);
  /*
  Serial.println("Encoder");
  Serial.println(encOne);
  
  */
  //reverseTillRotation(100,3.0);
}
