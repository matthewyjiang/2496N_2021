#pragma once
#include "main.h"

void tankControl(int max_mV_driver)
{
    int leftY = master.get_analog(ANALOG_LEFT_Y);
    int rightY = master.get_analog(ANALOG_RIGHT_Y);

    leftY = std::clamp(leftY, -max_mV_driver, max_mV_driver);
    rightY = std::clamp(rightY, -max_mV_driver, max_mV_driver);

    front_left_mtr.move(leftY);
    back_left_mtr.move(leftY);
    front_right_mtr.move(rightY);
    back_right_mtr.move(rightY);
}