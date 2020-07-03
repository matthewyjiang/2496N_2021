#include "main.h"

void stopDrive() {
  chassisPWM(0);
  chassisStraight.reset_variables();
  chassisTurn.reset_variables();
}

void drive(int distance, double maxVoltage){
  ChassisStraight.target = distance;
  ChassisStraight.setMaxVoltage(maxVoltage);
}

void pivot(int degree, double maxVoltage){
  double radian = (degree*acos(-1,0))/180;
}
