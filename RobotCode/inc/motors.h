// header file for motor controls

#ifndef MOTORS
#define MOTORS

#include "macros.h"

void motorSetup(motor m);

void motorMovement(motor m, int speed,int fv, int rv);

void forward(int speed);

void forwardTillRotation(int speed, float rotations);

void reverse(int speed);

void turnLeft(int speed);

void turnRight(int speed);

void off();

#endif