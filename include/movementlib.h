#pragma once
#include "main.h"

extern enum turnDirection;

extern void disableChassisPID();

extern void drive(int distance, double maxVoltage);

extern void drive(int distance, double maxVoltage, bool blocking, int threshold);

extern void drive(int distance, double maxVoltage, int count);

extern void pivot(int degree, double maxVoltage);

extern void pivot(int degree, double maxVoltage, bool blocking, int threshold);

extern void pivot(int degree, double maxVoltage, int timer);

extern void stopDrive();
