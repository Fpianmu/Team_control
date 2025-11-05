#ifndef PIN_DEFNITION_H
#define PIN_DEFNITION_H

#include <Arduino.h>

//PS2 Pins
#define PS2_DAT PA4
#define PS2_CMD PA5
#define PS2_CS PA6
#define PS2_CLK PA7

//Motor Pins
#define M1_IN1 PB0//左前
#define M1_IN2 PA1
#define M2_IN1 PB1//右前
#define M2_IN2 PA3
#define M3_IN1 PB10//左后
#define M3_IN2 PB14
#define M4_IN1 PB11//右后
#define M4_IN2 PB13
#define PWM_FREQUENCY 20000 //20kHz
#define PWM_RESOLUTION 8

//Status LED Pin
#define LED_PIN PC13

#endif 