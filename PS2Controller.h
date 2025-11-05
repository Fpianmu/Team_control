#ifndef PS2_CONTROLLER_H
#define PS2_CONTROLLER_H

class PS2Controller {
public:
    PS2Controller();
    bool begin();
    bool read();

    //Joystick
    int leftJoyX, leftJoyY, rightJoyX, rightJoyY;

    //Buttons
    bool btnCross, btnCircle, btnSquare, btnTriangle;
    bool btnL1, btnL2, btnR1, btnR2, btnStart, btnSelect;

private:
    bool connected;
};

#endif