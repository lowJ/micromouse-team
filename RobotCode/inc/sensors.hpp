// Header file to use different sensors like encoders or IR recivers

#ifndef SENSORS
#define SENSORS

// Structure to allow for easier use of encoders
typedef struct{
  int pin1, pin2, 
  volatile int ticks;
  int ticks_last, ticks_current;
  bool reverse;
  void increment();
} encoder;

encoder FL_enc = {FL_encoder_1,FL_encoder_2,0, 0, 0, true};
encoder FR_enc = {FR_encoder_1,FR_encoder_2,0, 0, 0, false};


void setupEncoder();

void setupInterrupt();

void resetEncoders();

int IR_vals[3] = {0,0,0};

void setupIR();

void pulseIR();

bool wallForward(); // TODO

bool wallLeft(); // TODO

bool wallRight(); // TODO

#endif