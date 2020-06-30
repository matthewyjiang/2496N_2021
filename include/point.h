#pragma once
#include "main.h"

class Point {
    
    public:
    double x;
    double y;

    Point();
    Point(double x, double y);

    double getDistance(Point p);

};