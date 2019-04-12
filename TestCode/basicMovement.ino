typedef struct{
  int motorEN, motorForward, motorReverse;
} motor;

motor FL = {0,0,0}; //format as {motorEN,motorForward,motorReverse}
motor FR = {0,0,0};
motor BL = {0,0,0};
motor BR = {0,0,0};
motor motors[4] = {FL,FR,BL,BR};

int recieverFront = 0;

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

void reverse(int speed){
  for (int i = 0; i <= 3; i++){
    motorMovement(motors[i],speed,0,1);
  }
}

void off(int speed){
  for (int i = 0; i <= 3; i++){
    motorMovement(motors[i],speed,0,0);
  }
}

bool detectWall(int reciever, int threshold){
  return threshold <= analogRead(reciever);
}

void setup() {
  for (int i = 0; i <= 3; i++){
    motorSetup(motors[i]);
  }
  pinMode(recieverFront,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
