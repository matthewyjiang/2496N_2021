#include "main.h"

void stopDrive() {
  chassisPWM(0);
  chassisStraight.reset_variables();
  chassisTurn.reset_variables();
}

void drive(int target, int maxVoltage){
  chassisStraight.target  = target;
  chassisStraight.max_mV  = maxVoltage;
  pros::delay(25);
}

void drive(int target, int maxVoltage, bool blocking){
  drive(target, maxVoltage);
  if(blocking){
    while(fabs(chassisStraight.error) > 5){pros::delay(10);}
    pros::delay(50);
    stopDrive();
    pros::delay(10);
  }
}

void drive(int target, int maxVoltage, int count){
  drive(target, maxVoltage);
  int i = 0;
  while(fabs(chassisStraight.error) > 5){
    i++;
     pros::delay(10);
     if(i >= count){
        break;
     }
  }
  stopDrive();
  pros::delay(10);
}
