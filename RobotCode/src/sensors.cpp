// Adds functions for using different sensors on the robot

#include <Arduino.h>
#include "../inc/sensors.hpp"
#include "../inc/marcros.hpp"

// Function to tick up an encoder
void encoder::increment()
{
  //Serial.println("Encoder call");
  int incr;
  if (reverse) {incr = -1;}
  else {incr = 1;}
  enc_current = digitalRead(m.encP1);

  if (enc_last != enc_current){
   
    if (enc_current != digitalRead(m.encP2)){
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
    this->ticks++;
}

// Sets up the encoder pins
void setupEncoder()
{
    pinMode(FL_enc.pin1,INPUT);
    pinMode(FR_enc.pin1,INPUT);
    pinMode(BL_enc.pin1,INPUT);
    pinMode(BR_enc.pin1,INPUT);

    pinMode(FL_enc.pin2,INPUT);
    pinMode(FR_enc.pin2,INPUT);
    pinMode(BL_enc.pin2,INPUT);
    pinMode(BR_enc.pin2,INPUT);
}

// Starts up interupts to allow for the encoder values to tick up
void setupInterrupt()
{
    attachInterrupt(digitalPinToInterrupt(FL_enc.pin1), FL_enc.increment,CHANGE);
    attachInterrupt(digitalPinToInterrupt(FR_enc.pin1), FR_enc.increment,CHANGE);
    attachInterrupt(digitalPinToInterrupt(BL_enc.pin1), BL_enc.increment,CHANGE);
    attachInterrupt(digitalPinToInterrupt(BR_enc.pin1), BR_enc.increment,CHANGE);

    attachInterrupt(digitalPinToInterrupt(FL_enc.pin2), FL_enc.increment,CHANGE);
    attachInterrupt(digitalPinToInterrupt(FR_enc.pin2), FR_enc.increment,CHANGE);
    attachInterrupt(digitalPinToInterrupt(BL_enc.pin2), BL_enc.increment,CHANGE);
    attachInterrupt(digitalPinToInterrupt(BR_enc.pin2), BR_enc.increment,CHANGE);
}

// Resets all the encoder values
void resetEncoders()
{
    FL_enc.ticks = 0
    FR_enc.ticks = 0
    BL_enc.ticks = 0
    BR_enc.ticks = 0
}

// Sets up IR emmiters and reciver pins
void setupIR()
{
    pinMode(receiverF,INPUT)
    pinMode(receiverL,INPUT)
    pinMode(receiverR,INPUT)

    pinMode(emitterF,OUTPUT)
    pinMode(emitterL,OUTPUT)
    pinMode(emitterR,OUTPUT)
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
        IR_vals[i] = digitalRead(recievers[i])
        digitalWrite(emitters[i],LOW);
        delay(2);       
    }
}
