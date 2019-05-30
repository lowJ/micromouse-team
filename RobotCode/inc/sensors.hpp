// Header file to use different sensors like encoders or IR recivers

#ifndef SENSORS
#define SENSORS

// Structure to allow for easier use of encoders
typedef struct{
  int pin1, pin2, ticks;
  void increment();
} encoder;

encoder FL_enc = {FL_encoder_1,FL_encoder_2,0};
encoder FR_enc = {FR_encoder_1,FR_encoder_2,0};
encoder BL_enc = {BL_encoder_1,BL_encoder_2,0};
encoder BR_enc = {BR_encoder_1,BR_encoder_2,0}; 

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