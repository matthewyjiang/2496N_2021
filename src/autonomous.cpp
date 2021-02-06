#include "main.h"

//this is where the auton be

void auton(){
    intakeControl(-127);
    depositControl(-127);
    pros::delay(500); 
    intakeControl(127);
    depositControl(0);

    drive(5000, 8000, 1000);
    drive(-5000, 8000, 1000);

}
