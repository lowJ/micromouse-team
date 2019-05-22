//PID.cpp
/*working variables*/
#include <Arduino.h>
#include "PID.h"
#include "marcros.h"
int sampleTime = 500; //0.5 sec

PID::PID(int target_speed, int sample_time, double Kp, double Ki, double Kd)
: sample_time(sampleTime), kp(Kp), ki(Ki), kd(Kd){
}

int PID::compute()
{
   unsigned long now = millis();
   int timeChange = (now - lastTime);
   
   if(timeChange>=sample_time)
   {
      /*Compute all the working error variables*/
      current_speed = current_rotations/timeChange;
      double error = target_speed - current_speed;
      integral_term += (ki * error);
      double dInput = (current_speed - lastInput);
 
      /*Compute PID rotation_change_output*/
      rotation_change_output = kp * error + integral_term - kd * dInput;
      /*Remember some variables for next time*/
      lastInput = current_speed;
      lastTime = now;
      return rotation_change_output;
   }
   else:
      return 0;

}
void PID::setTarget(int new_target)
{
 target_speed = new_target;
}
 
void PID::setTunings(double& Kp, double& Ki, double& Kd)
{
  double sample_timeInSec = ((double)sample_time)/1000;
   kp = Kp;
   ki = Ki * sample_timeInSec;
   kd = Kd / sample_timeInSec;
}
 
void PID::setsample_time(int Newsample_time)
{
   if (Newsample_time > 0)
   {
      double ratio  = (double)Newsample_time / (double)sample_time;
      ki *= ratio;
      kd /= ratio;
      sample_time = (unsigned long)Newsample_time;
   }
}

void PID::setTargetRotation(int new target_speed)
{
 target_speed = new target_speed;

}