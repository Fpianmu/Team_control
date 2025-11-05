#include "MecanumController.h"
#include <cmath>
#include <algorithm>
#include <Arduino.h>

MecanumController::MecanumController() {
    //初始化校准系数
    for(int i = 0; i<4; i++) {
        calibration[i] = 1.0f;
    }
}

void MecanumController::move(float vx, float vy, float omega) {
    // 应用死区
    applyDeadzone(vx, vy, omega);

    //计算四个轮子速度
    float w1 = (vx - vy - omega) * calibration[0];
    float w2 = (vx + vy + omega) * calibration[1];
    float w3 = (vx + vy - omega) * calibration[2];
    float w4 = (vx - vy + omega) * calibration[3];

    // 归一化速度
    normalize(w1, w2, w3, w4);

    // 发送速度命令>setMotor(1, w1);
    MotorDriver motor;
    motor.setMotor(1, static_cast<int>(w1 * 255));
    motor.setMotor(2, static_cast<int>(w2 * 255));
    motor.setMotor(3, static_cast<int>(w3 * 255));
    motor.setMotor(4, static_cast<int>(w4 * 255));
}
void MecanumController::applyDeadzone(float& vx, float& vy, float& omega) {
    float deadzone = 0.1f;
    if (fabs(vx) < deadzone) vx = 0;
    if (fabs(vy) < deadzone) vy = 0;
    if (fabs(omega) < deadzone) omega = 0;
}
void MecanumController::normalize(float& w1, float& w2, float& w3, float& w4) {
    float maxVal = max(max(fabs(w1), fabs(w2)), max(fabs(w3), fabs(w4)));
    if (maxVal > 1.0f ) {
        w1 /= maxVal;
        w2 /= maxVal;
        w3 /= maxVal;
        w4 /= maxVal;
    }
}
void MecanumController::setCalibration(float c0, float c1, float c2, float c3) {
    calibration[0] = c0;
    calibration[1] = c1;
    calibration[2] = c2;
    calibration[3] = c3;
}