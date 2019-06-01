//File to store all constansts used throughout the code such as pin numbers

#ifndef MACRO
#define MACRO

// Different Maze Constants
#define MAZE_WIDTH 16
#define MAZE_HEIGHT 16
#define BLOCK_SIZE 18


// Defines a motor stucture to allow for easier acess to pins
typedef struct{
  int motorEN, motorForward, motorReverse, encP1, encP2; 
} motor;

// Define movespeed constants
#define forwardSpeed 100
#define turnSpeed 80

// Define front left motor pins
#define FL_motorEN 8
#define FL_motorForward 5
#define FL_motorReverse 6
#define FL_encP1 17
#define FL_encP2 18
const motor FL = {FL_motorEN,FL_motorForward,FL_motorReverse,true};

// Define front right motor pins
#define FR_motorEN 7
#define FR_motorForward 3
#define FR_motorReverse 4
#define FR_encP1 19
#define FR_encP2 20
const motor FR {FR_motorEN,FR_motorForward,FR_motorReverse,false};

/*  //Removed BL and BR motors
// Define back left motor pins
#define BL_motorEN 8
#define BL_motorForward 0
#define BL_motorReverse 0
#define BL_encoder 0
const motor BL {BL_motorEN,BL_motorForward,BL_motorReverse,true};

// Define back right motor pins
#define BR_motorEN 7
#define BR_motorForward 0
#define BR_motorReverse 0
#define BR_encoder 0
const motor BR {BR_motorEN,BR_motorForward,BR_motorReverse,false};
*/
// Define motor array to allow for looping through motors
const motor motors[2] = {FL,FR};

// Define IR reciever pin values
#define receiverF 15
#define receiverL 14
#define receiverR 16
const int recievers[3] = {receiverL,receiverF,receiverR};

// Define IR emitter pin values
#define emitterF 1
#define emitterL 0
#define emitterR 2
const int emitters[3] = {emitterL,emitterF,emitterR};

// Define motor encoder pins
#define FL_encoder 0
#define FR_encoder 0
#define BL_encoder 0
#define BR_encoder 0

// Define important encoder/movement constants
#define ENCODER_STEPS 360
#define ENCODER_CIRC  2.9*PI //in cm
#define ROBOT_DIAMETER 0 // the distance from the center of the FL wheel to the center of the BR wheel
#define ROBOT_TURNING_CIRC ROBOT_DIAMETER * PI 

#define STEP_TO_CM ENCODER_CIRC / ENCODER_STEPS
#define CM_TO_STEP  1 / STEP_TO_CM

#define COS_45 0.70710678118 // this is literally cos(45 deg)
#define DEG_TO_STEP CM_TO_STEP * ROBOT_TURNING_CIRC * COS_45 / 360 // transforms a certain amt of degrees to the encoder steps required to make the turn 
#define STEP_TO_DEG 1 / DEG_TO_STEP

#endif