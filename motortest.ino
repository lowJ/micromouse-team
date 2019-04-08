
//
//
//    MOVEMENT CODE   //
//
int encoder_pin = 10;
const int ENCODER_STEPS = 360;
const float ENCODER_CIRC = 2.9*PI; //in cm
const float STEP_TO_CM = ENCODER_CIRC / ENCODER_STEPS;
const float CM_TO_STEP = 1 / STEP_TO_CM;
int encA = 0;
typedef struct{
  int motorEN, motorForward, motorReverse;
} motor;

motor FL = {0,0,0}; //format as {motorEN,motorForward,motorReverse}
motor FR = {0,0,0};
motor BL = {0,0,0};
motor BR = {0,0,0};
motor motors[4] = {FL,FR,BL,BR};

int receiverFront = 0;

void motorSetup(motor m){
  pinMode(m.motorEN,OUTPUT);
  pinMode(m.motorForward,OUTPUT);
  pinMode(m.motorReverse,OUTPUT);
}

void motorMovement(motor m, int speed,int fv, int rv){
  analogWrite(m.motorEN,speed);
  digitalWrite(m.motorForward,fv);
  digitalWrite(m.motorReverse,rv);
}

void forward(int speed){
  for (int i = 0; i <= 3; i++){
    motorMovement(motors[i],speed,1,0);
  }
}
void forwardTillRotation(int speed, float rotations){
  motorMovement(motors[0], speed,1,0);
  while(encA < rotations * ENCODER_STEPS){
    
  }
}

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


//
//
//    ENCODER CODE    //
//

void setupEncoder(){
  pinMode(encoder_pin,INPUT);
}



void encoderA(){
  encA += 1;
  }

void setupInterrupt(){
  attachInterrupt(encoder_pin, encoderA,CHANGE);
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
  setupEncoder();
  setupInterrupt();
  //pinMode(receiverFront,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //forward(150);
  forwardTillRotation(150,5.0);
  /*if(detectWall(receiverFront,200)){
    off();
    turnLeft(75);
    delay(200);
    off();
  }
  */
}
