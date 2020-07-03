#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

enum chassisPIDStates{
	NORMAL,
	PIVOT,
	DISABLE
};

chassisPIDStates chassisState = DISABLE;

void drive_PID() {
	chassisStraight.slewOverrideEnable = true;
	chassisTurn.slewOverrideEnable = true;
	while (true) {
		if(chassisState == NORMAL){
			chassisStraight.setInput(left_encoder.get_value());
			chassisStraight.moveTo();

			chassisPWM(chassisStraight.getOutput());
		}
		else if(chassisState == PIVOT){
			chassisTurn.setInput(imu.get_rotation()-gyroOffset)
      chassisTurn.moveTo();

      chassisPWM(chassisTurn.getOutput(), -chassisTurn.getOutput());
		}
		pros::delay(20);
	}
}

void initialize() {
	chassisStraight.slewRate = 300;
	chassisTurn.slewRate = 300;
	pros::Task drivePID(drive_PID, "drivepid");
}
