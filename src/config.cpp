#include "main.h"
#include "config.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor front_left_mtr(9, pros::E_MOTOR_GEARSET_36);
pros::Motor back_left_mtr(6, pros::E_MOTOR_GEARSET_36);
pros::Motor front_right_mtr(7, pros::E_MOTOR_GEARSET_36, true);
pros::Motor back_right_mtr(8, pros::E_MOTOR_GEARSET_36, true);
pros::Motor left_roller_mtr(13, pros::E_MOTOR_GEARSET_18);
pros::Motor right_roller_mtr(14, pros::E_MOTOR_GEARSET_18, true);
pros::Motor indexer_mtr(15, pros::E_MOTOR_GEARSET_18);
pros::Motor depositor_mtr(16, pros::E_MOTOR_GEARSET_18);

pros::ADIEncoder left_encoder(1,2);
pros::ADIEncoder right_encoder(3,4);

pros::Imu imu(20);
