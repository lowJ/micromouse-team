//File to store all constansts used throughout the code such as pin numbers

#ifndef MACRO
#define MACRO

// Defines a motor stucture to allow for easier acess to pins
typedef struct{
  int motorEN, motorForward, motorReverse;
} motor;

// Define front left motor pins
#define FL_motorEN 0
#define FL_motorForward 0
#define FL_motorReverse 0
const motor FL = {FL_motorEN,FL_motorForward,FL_motorReverse};

// Define front right motor pins
#define FR_motorEN 0
#define FR_motorForward 0
#define FR_motorReverse 0
const motor FR {FR_motorEN,FR_motorForward,FR_motorReverse};

// Define back left motor pins
#define BL_motorEN 0
#define BL_motorForward 0
#define BL_motorReverse 0
const motor BL {BL_motorEN,BL_motorForward,BL_motorReverse};

// Define back right motor pins
#define BR_motorEN 0
#define BR_motorForward 0
#define BR_motorReverse 0
const motor BR {BR_motorEN,BR_motorForward,BR_motorReverse};

// Define motor array to allow for looping through motors
const motor motors[4] = {FL,FR,BL,BR};

// Define IR reciever pin values
#define receiverF 0
#define receiverL 0
#define receiverR 0

// Define motor encoder pins
#define FL_encoder 0
#define FR_encoder 0
#define BL_encoder 0
#define BR_encoder 0

// Define important encoder/movement constants
#define ENCODER_STEPS 360
#define ENCODER_CIRC  2.9*PI //in cm
#define STEP_TO_CM ENCODER_CIRC / ENCODER_STEPS
#define CM_TO_STEP = 1 / STEP_TO_CM

#endif