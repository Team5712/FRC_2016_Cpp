#ifndef ROBOTMAP_H
#define ROBOTMAP_H

class RobotMap
{

public:
	RobotMap();

	const static int DRIVESTICK_JOYSTICK;
	const static int SHOOTSTICK_JOYSTICK;

// Drive Stick button / trigger mappings
	const static int SHIFT_GEAR_TRIGGER;
	const static int INVERT_MOTORS_BUTTON;
	const static int NORMALIZE_MOTORS_BUTTON;
	const static int TURN_DEGREES_BUTTON;
	const static int SOLENOID_OUT_BUTTON;
	const static int SOLENOID_IN_BUTTON;

// Shoot Stick button / trigger mappings
	const static int SHOOT_TRIGGER;
	const static int INTAKE_BUTTON;
	const static int ARM_UP_BUTTON;
	const static int ARM_DOWN_BUTTON;
	const static int SOLENOID_OUT_BUTTON_2;
	const static int SOLENOID_IN_BUTTON_2;

	const static int LEFT_FRONT_MOTOR;
	const static int LEFT_REAR_MOTOR;
	const static int RIGHT_FRONT_MOTOR;
	const static int RIGHT_REAR_MOTOR;

	const static int SHOOTER_LEFT_MOTOR;
	const static int SHOOTER_RIGHT_MOTOR;
	const static int SHOOTER_LIFT_MOTOR;

	const static int SHOOTER_ENCODER_A;
	const static int SHOOTER_ENCODER_B;

	const static int RIGHT_DRIVE_ENCODER_A;
	const static int RIGHT_DRIVE_ENCODER_B;

	const static int LEFT_DRIVE_ENCODER_A;
	const static int LEFT_DRIVE_ENCODER_B;

	const static int COMPRESSOR;

	const static int SHOOTER_SOLENOID_A;
	const static int SHOOTER_SOLENOID_B;

	const static int SHIFTER_SOLENOID_A;
	const static int SHIFTER_SOLENOID_B;

private:


};

#endif
