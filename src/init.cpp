#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
chassisPIDStates chassisState = DISABLE;

void drive_PID() {
	chassisStraight.slewOverrideEnable = true;
	chassisTurn.slewOverrideEnable = true;
	while (true) {
		if(chassisState == NORMAL){
			chassisStraight.setInput(front_left_mtr.get_position());
			chassisAngle.setInput(imu.get_rotation() + gyroOffset);
			chassisStraight.moveTo();
			chassisAngle.moveTo();

			chassisPWM(chassisStraight.getOutput()+chassisAngle.getOutput(), chassisStraight.getOutput()-chassisAngle.getOutput());
		}
		else if(chassisState == PIVOT){
			chassisTurn.setInput(imu.get_rotation()-gyroOffset);
      		chassisTurn.moveTo();

      	chassisPWM(chassisTurn.getOutput(), -chassisTurn.getOutput());
		}
		pros::delay(20);
	}
}

void debug_stream(){
	std::cout << "x: " << odom.getX() << ", y:" << odom.getY() << std::endl;
	pros::delay(20);
}

void initialize() {
	chassisStraight.slewRate = 300;
	chassisTurn.slewRate = 300;
	chassisAngle.setMaxVoltage(6000);
	chassisAngle.slewOverrideEnable = false;
	front_left_mtr.set_current_limit(2200);
    back_left_mtr.set_current_limit(2200);
    front_right_mtr.set_current_limit(2200);
    back_right_mtr.set_current_limit(2200);
	pros::Task drivePID(drive_PID, "drivepid");
	pros::Task debugStream(debug_stream, "debugstream");
}
