// Adds functions for using different sensors on the robot

#include <Arduino.h>
#include "../inc/sensors.hpp"
#include "../inc/marcros.hpp"

// Function to tick up an encoder
void encoder::increment()
{
    int inc;
    if (this.reverse) {inc = -1;}
    else {inc = 1;}
    this.ticks_current = digitalRead(this.pin1);
    if (this.ticks_last != this.ticks_current)
    {
        if (this.ticks_current != digitalRead(this.pin2))
        {
            this.ticks += inc;
        }
        else
        {
            this.ticks -= inc;
        }
        
    }
    this->ticks++;
}

// Sets up the encoder pins
void setupEncoder()
{
    pinMode(FL_enc.pin1,INPUT);
    pinMode(FR_enc.pin1,INPUT);

    pinMode(FL_enc.pin2,INPUT);
    pinMode(FR_enc.pin2,INPUT);

    FL_enc.ticks_last = digitalRead(FL_enc.pin1);
    FR_enc.tick_last = digitalRead(FR_enc.pin1);
}

// Starts up interupts to allow for the encoder values to tick up
void setupInterrupt()
{
    attachInterrupt(FL_enc.pin1, FL_enc.increment,CHANGE);
    attachInterrupt(FR_enc.pin1, FR_enc.increment,CHANGE);

    attachInterrupt(FL_enc.pin2, FL_enc.increment,CHANGE);
    attachInterrupt(FR_enc.pin2, FR_enc.increment,CHANGE);
}

// Resets all the encoder values
void resetEncoders()
{
    FL_enc.ticks = 0;
    FR_enc.ticks = 0;
}

// Sets up IR emmiters and reciver pins
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

// Pulses all IR sensors and places output in IR_vals, {left value,middle value,right value}
void pulseIR()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(emitters[i],HIGH);
        delay(3);
        IR_vals[i] = digitalRead(recievers[i]);
        digitalWrite(emitters[i],LOW);
        delay(2);       
    }
}
