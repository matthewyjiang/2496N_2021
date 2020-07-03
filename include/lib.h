#pragma once
#include "main.h"

extern enum chassisPIDStates;

extern chassisPIDStates chassisState;

extern void chassisPWM(int voltageLeft, int voltageRight);

extern void chassisPWM(int voltage);

extern void tankControl(int maxOutput);

extern void intakeControl(int speed);