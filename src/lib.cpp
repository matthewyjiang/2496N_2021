#include "main.h"

void chassisPWM(int voltageLeft, int voltageRight){
    front_left_mtr.move_voltage(voltageLeft);
    back_left_mtr.move_voltage(voltageLeft);
    front_right_mtr.move_voltage(voltageRight);
    back_right_mtr.move_voltage(voltageRight);
}

void chassisPWM(int voltage){
    chassisPWM(voltage, voltage);
}

