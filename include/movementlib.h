#pragma once
#include "main.h"

namespace turnDirection{
    enum eDirection{
        LEFT = -1,
        RIGHT = 1
    };
}

extern void disableChassisPID();

extern void drive(int distance, double maxVoltage); 

extern void drive(int distance, double maxVoltage, bool blocking, int threshold);

extern void drive(int distance, double maxVoltage, int count);

extern void pivot(int degree, int direction, double maxVoltage);

extern void pivot(int degree, int direction, double maxVoltage, bool blocking, int threshold);

extern void pivot(int degree, int direction, double maxVoltage, int timer);

extern void stopDrive();
