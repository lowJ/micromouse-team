// Header file to use different sensors like encoders or IR recivers

#ifndef SENSORS
#define SENSORS

// Structure to allow for easier use of encoders
typedef struct{
  int pin, ticks;
  void increment();
} encoder;

encoder FL_enc = {FL_encoder,0};
encoder FR_enc = {FR_encoder,0};
encoder BL_enc = {BL_encoder,0};
encoder BR_enc = {BR_encoder,0}; 

void setupEncoder();

void setupInterrupt();

void resetEncoders();

int IR_vals[3] = {0,0,0};

void setupIR();

void pulseIR();

#endif