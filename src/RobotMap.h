#ifndef ROBOTMAP_H
#define ROBOTMAP_H

class RobotMap
{

public:
	RobotMap();

	static int DRIVESTICK_JOYSTICK = 0;
	static int SHOOTSTICK_JOYSTICK = 1;

// Drive Stick button / trigger mappings
	static int SHIFT_GEAR_TRIGGER = 1;
	static int INVERT_MOTORS_BUTTON = 3;
	static int NORMALIZE_MOTORS_BUTTON = 4;
	static int TURN_DEGREES_BUTTON = 6;
	static int SOLENOID_OUT_BUTTON = 7;
	static int SOLENOID_IN_BUTTON = 8;

// Shoot Stick button / trigger mappings
	static int SHOOT_TRIGGER = 1;
	static int INTAKE_BUTTON = 2;
	static int ARM_UP_BUTTON = 5;
	static int ARM_DOWN_BUTTON = 6;
	static int SOLENOID_OUT_BUTTON_2 = 10;
	static int SOLENOID_IN_BUTTON_2 = 11;

	static int LEFT_FRONT_MOTOR = 0;
	static int LEFT_REAR_MOTOR = 1;
	static int RIGHT_FRONT_MOTOR = 2;
	static int RIGHT_REAR_MOTOR = 3;

	static int SHOOTER_LEFT_MOTOR = 4;
	static int SHOOTER_RIGHT_MOTOR = 5;
	static int SHOOTER_LIFT_MOTOR = 6;

	static int SHOOTER_ENCODER_A = 0;
	static int SHOOTER_ENCODER_B = 1;

	static int RIGHT_DRIVE_ENCODER_A = 2;
	static int RIGHT_DRIVE_ENCODER_B = 3;

	static int LEFT_DRIVE_ENCODER_A = 4;
	static int LEFT_DRIVE_ENCODER_B = 5;

	static int COMPRESSOR = 0;

	static int SHOOTER_SOLENOID_A = 0;
	static int SHOOTER_SOLENOID_B = 1;

	static int SHIFTER_SOLENOID_A = 2;
	static int SHIFTER_SOLENOID_B = 3;

private:


};

#endif
