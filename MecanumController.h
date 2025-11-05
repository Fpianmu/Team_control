#ifndef MECANUM_CONTROLLER_H
#define MECANUM_CONTROLLER_H
#include <MotorDriver.h>
class MecanumController {
public:
    MecanumController();
    void move(float vx, float vy, float omega);
    void setCalibration(float c0, float c1, float c2, float c3);

private:
    void applyDeadzone(float &vx, float &vy, float &omega);
    void normalize(float &w1, float &w2, float &w3, float &w4);
    float calibration[4];
};

#endif