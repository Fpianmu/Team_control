#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <cstdint>

class MotorDriver {
public:
    MotorDriver();
    void setMotor(int motorNum,int speed);
private:
    int deadzone;
    int currentSpeed[4];
};

#endif