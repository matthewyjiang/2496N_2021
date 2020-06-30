#include "point.h"

Point::Point(){
    this->x = 0;
    this->y = 0;
}
    
Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

double Point::getDistance(Point p){
    return pow(pow(this->x - p.x, 2)+pow(this->y - p.y,2), 0.5);
}