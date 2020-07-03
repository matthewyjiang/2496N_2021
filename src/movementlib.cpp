#include "main.h"

void stopDrive() {
  chassisPWM(0);
  chassisStraight.reset_variables();
  chassisTurn.reset_variables();
}

void disableChassisPID(){
  chassisState = DISABLE;
}

void drive(int distance, double maxVoltage){
  chassisState = NORMAL;
  chassisStraight.setTarget(distance);
  chassisStraight.setMaxVoltage(maxVoltage);
}

void drive(int distance, double maxVoltage, bool blocking, int threshold){
  drive(distance, maxVoltage);
  pros::delay(50);
  if(blocking){
    while(abs(chassisStraight.getError()) > threshold){
      pros::delay(20);
    }
    stopDrive();
    disableChassisPID();
  }
}

void drive(int distance, double maxVoltage, int timer){//count in milliseconds, blocking by default
  drive(distance, maxVoltage);
  int count = 0;
  while(count <= timer){
    count+=10;
    pros::delay(10);
  }
  stopDrive();
  disableChassisPID();
}

void pivot(int degree, double maxVoltage){
  chassisState = PIVOT;
  chassisTurn.setMaxVoltage(maxVoltage);
  chassisTurn.setTarget(degree);
}

void pivot(int degree, double maxVoltage, bool blocking, int threshold){
  pivot(degree, maxVoltage);
  pros::delay(50);
  if(blocking){
    while(abs(chassisTurn.getError()) > threshold){
      pros::delay(20);
    }
    stopDrive();
    disableChassisPID();
  }
}

void pivot(int degree, double maxVoltage, int timer){//count in milliseconds, blocking by default
  pivot(degree, maxVoltage);
  int count = 0;
  while(count <= timer){
    count+=10;
    pros::delay(10);
  }
  stopDrive();
  disableChassisPID();
}

// count is easier for programming autons fast, because it allows the PID to settle every time.
// blocking function threshold should be tuned