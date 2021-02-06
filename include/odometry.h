#pragma once
#include "main.h"
#include "point.h"

extern void resetEncoders();

class Odometry: public Point {
    public:
    
    double theta;

    void updateValues(double x, double y, double theta);

};

extern Odometry odom;