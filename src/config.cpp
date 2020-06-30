#include "main.h"
#include "config.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor front_left_mtr(1, pros::E_MOTOR_GEARSET_36, true);
pros::Motor back_left_mtr(2, pros::E_MOTOR_GEARSET_36, true);
pros::Motor front_right_mtr(2, pros::E_MOTOR_GEARSET_36);
pros::Motor back_right_mtr(4, pros::E_MOTOR_GEARSET_36);