//PID.h


class PID
{
    public:
    PID(int target_speed, int sample_time, double kp, double ki, double kd);
    int compute();
    void setTarget(int new_target);
    void setTunings(double& Kp, double& Ki, double& Kd);
    void setSampleTime(int NewSampleTime);

    private:
    int sampleTime;
    double kp, ki, kd;
    unsigned long lastTime;
    double current_speed, rotation_change_output, target_speed;
    double integral_term, lastInput;

};




