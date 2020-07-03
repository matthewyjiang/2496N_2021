#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

enum chassisPIDState {On = 1, Off = 0};

void drive_PID() {
	chassisStraight.slewOverrideEnable = true;
	while (true) {

	}
}

void initialize() {
	pros::Task drivePID();
}
