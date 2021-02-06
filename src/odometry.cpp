#include "main.h"

void resetEncoders(){
  left_encoder.reset();
  right_encoder.reset();
}

void Odometry::updateValues(double x, double y, double theta){
  this->x = x;
  this->y = y;
  this->theta = theta;
}

Odometry odom;