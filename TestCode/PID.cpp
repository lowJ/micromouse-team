//PID.cpp
/*working variables*/
#include <Arduino.h>
#include "..\\inc\\PID.hpp"
#include "..\\inc\\marcros.hpp"
int sampleTime = 500; //0.5 sec
int pwm_multi = 4;

PID::PID(double targetSpeed, int sampleTime, double Kp, double Ki, double Kd)
: target_speed(targetSpeed), sample_time(sampleTime), kp(Kp), ki(Ki), kd(Kd)
{
	lastTime = millis();
	last_num_rotations = 0;
}

double PID::compute(double current_rotations)
{
   double pwm_change;
   unsigned long now = millis();
   int timeChange = (now - lastTime);
   if(timeChange>=sample_time)
   {
      /*Compute all the working error variables*/
      current_speed = double(abs(current_rotations) - last_num_rotations)/double(timeChange/1000);
	Serial.print("Current speed, rps:");
	Serial.println(current_speed);
      double error = target_speed - current_speed;
      integral_term += (ki * error);
      double dInput = (current_speed - lastInput);
 
      /*Compute PID rotation_change_output*/
      rotation_change_output = kp * error + integral_term - kd * dInput;
      /*Remember some variables for next time*/
      lastInput = current_speed;
      lastTime = now;
      last_num_rotations = current_rotations;
      pwm_change = rotation_change_output*pwm_multi; // converts rps change to pwm change
      Serial.println(pwm_change);
      return pwm_change; 
   }
   else
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
 
void PID::setSampleTime(int Newsample_time)
{
   if (Newsample_time > 0)
   {
      double ratio  = (double)Newsample_time / (double)sample_time;
      ki *= ratio;
      kd /= ratio;
      sample_time = (unsigned long)Newsample_time;
   }
}
//This method and setTarget currently do the same thing, this may change
void PID::setTargetRotation(int new_target_pw)
{
 target_speed = new_target_pw;

}