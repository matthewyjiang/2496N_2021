#include "main.h"

void stopDrive() {
  chassisPWM(0);
  chassisStraight.reset_variables();
  chassisTurn.reset_variables();
}

void drive(int distance, double maxVoltage){
  chassisState = NORMAL;
  ChassisStraight.target = distance;
  ChassisStraight.setMaxVoltage(maxVoltage);
}

void pivot(int degree, double maxVoltage){
  chassisState = PIVOT;
  ChassisTurn.setMaxVoltage(maxVoltage);
  double radian = (degree*acos(-1,0))/180;
  ChassisTurn.target = chassisTurn.currentPosition - radian;
}
