#include "main.h"

//this is where the auton be

void auton(){
    intakeControl(-127);
    depositControl(-127);
    pros::delay(500); 
    intakeControl(127);
    depositControl(0);

    drive(1000, 8000, 1000);
    intakeControl(0);
    pivot(135, turnDirection::LEFT, 1000);
    drive(1000, 8000, 1000);
    depositControl(127);
    intakeControl(127);
    pros::delay(5000);
    intakeControl(0);
    depositControl(0);
    drive(1000, -8000, 1000);
    pivot (180, turnDirection::RIGHT, 1000);
    intakeControl(127);

    drive(4000, 8000, 1000);
    intakeControl(0);
    pivot(135, turnDirection::RIGHT, 1000);
    drive(2000, 8000, 1000);
    intakeControl(127);
    depositControl(127);
    pros::delay(5000);
    intakeControl(0);
    depositControl(0);
    drive(500, -8000, 1000);

    pivot(90, turnDirection::LEFT, 1000);
    drive(2000, 8000, 1000);
    pivot(45, turnDirection::RIGHT, 1000);
    drive(1000, 8000, 1000);
    intakeControl(127);
    depositControl(127);
    pros::delay(5000);
    intakeControl(0);
    depositControl(0);
    drive(2000, -8000, 1000);
    pivot(45, turnDirection::LEFT, 1000);
    
    intakeControl(127);
    drive(2000, 8000, 1000);
    intakeControl(0);
    drive(500, -8000, 1000);
    pivot(90, turnDirection::LEFT, 1000);
    intakeControl(127);
    drive(2000, 8000, 1000);
    intakeControl(0);
    pivot(90, turnDirection::RIGHT, 1000);
    drive(500, 8000, 1000);
    intakeControl(127);
    depositControl(127);
    pros::delay(5000);
    intakeControl(0);
    depositControl(0);

    drive(500, -8000, 1000);
    pivot(90, turnDirection::LEFT, 1000);
    drive(2000, 8000, 1000);
    pivot(90, turnDirection::RIGHT, 1000);
    intakeControl(127);
    drive(500, 8000, 1000);
    intakeControl(0);
    drive(1000, -8000, 1000);
    pivot(45, turnDirection::LEFT, 1000);
    drive(1000, 8000, 1000);
    intakeControl(127);
    depositControl(127);
    pros::delay(5000);
    intakeControl(0);
    depositControl(0);

    drive(500, -8000, 1000);
    pivot(135, turnDirection::RIGHT, 1000);
    intakeControl(127);
    drive(1000, 8000, 1000);
    intakeControl(0);
    pivot(45, turnDirection::RIGHT, 1000);
    drive(1000, 8000, 1000);
    drive(200,-8000, 1000);
    drive(200, 8000, 1000);
    drive(200,-8000, 1000);
    drive(200, 8000, 1000);
    drive(200,-8000, 1000);
    pivot(5, turnDirection::LEFT, 1000);
    intakeControl(127);
    drive(300,-8000, 1000);
    intakeControl(0);
    depositControl(127);
    pros::delay(1000);
    depositControl(0);
    intakeControl(0);


    //testing creating new branch
}

void poggers(){
    intakeControl(-127);
    depositControl(-127);
    pros::delay(500); 
    intakeControl(127);
    depositControl(0);

    drive(1000, 8000, 1000);
    intakeControl(0);
    pivot(135, turnDirection::LEFT, 1000);
    drive(1000, 8000, 1000);
    depositControl(127);
    intakeControl(127);
    pros::delay(3000);
    intakeControl(0);
    depositControl(0);
    drive(1000, -8000, 1000);
    pivot (180, turnDirection::RIGHT, 1000);
    intakeControl(127);

    drive(4000, 8000, 1000);
    intakeControl(0);
    pivot(135, turnDirection::RIGHT, 1000);
    drive(2000, 8000, 1000);
    intakeControl(127);
    depositControl(127);
    pros::delay(3000);
    intakeControl(0);
    depositControl(0);
    drive(500, -8000, 1000);

    pivot(90, turnDirection::LEFT, 1000);
    drive(2000, 8000, 1000);
    pivot(45, turnDirection::RIGHT, 1000);
    drive(1000, 8000, 1000);
    intakeControl(127);
    depositControl(127);
    pros::delay(3000);
    intakeControl(0);
    depositControl(0);
    drive(2000, -8000, 1000);
    pivot(45, turnDirection::LEFT, 1000);
    
}