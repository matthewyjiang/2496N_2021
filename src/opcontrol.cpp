#include "main.h"

void tankControl(int maxOutput){
    int leftY = master.get_analog(ANALOG_LEFT_Y);
    int rightY = master.get_analog(ANALOG_RIGHT_Y);

    leftY = std::clamp(leftY, -maxOutput, maxOutput);
    rightY = std::clamp(rightY, -maxOutput, maxOutput);

    front_left_mtr.move(leftY);
    back_left_mtr.move(leftY);
    front_right_mtr.move(rightY);
    back_right_mtr.move(rightY);
}

void intakeControl(int speed){
    left_roller_mtr.move(speed);
    right_roller_mtr.move(speed);
}

void depositControl(int speed){
    depositor_mtr.move(speed);
    indexer_mtr.move(speed);
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {

    bool btnR1;
    bool btnR2;
    bool btnL1;
    bool btnL2;
    bool btnLeft;
    bool slowOuttake;

	while (true) {

        btnR1 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
        btnR2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
        btnL1 = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
        btnL2 = master.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
        btnLeft = master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);

		tankControl(127);

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
            slowOuttake = true;
            btnR1 = true;
        } else {
            slowOuttake = false;
        }
        
        if(btnR1){
            intakeControl(127);
        } else if(btnR2){
            intakeControl(-127);
        } else {
            intakeControl(0);
        }

        if(btnL1){
            depositControl(127);
        } else if(btnL2){
            depositControl(-70);
        } else if(slowOuttake){
            depositControl(-33);
        } else if(btnLeft){
            depositControl(70);
        } else {
            depositControl(0);
        }

		pros::delay(20);
	}
}
