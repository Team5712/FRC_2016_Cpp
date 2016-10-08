#include "OI.h"


OI::OI()
{

	driveStick = new Joystick(RobotMap::DRIVESTICK_JOYSTICK);
	shootStick = new Joystick(RobotMap::SHOOTSTICK_JOYSTICK);

	//driveStick Button Commands
	shiftGear_DriveStickTrigger = new JoystickButton(driveStick, 1);
	shiftGear_DriveStickTrigger->WhileHeld(new ShiftGear());

	invertMotors_DriveStickButton = new JoystickButton(driveStick, 3);
	invertMotors_DriveStickButton->WhenPressed(new InvertMotorsTrue());
	normalizeMotors_DriveStickButton = new JoystickButton(driveStick, 4);
	normalizeMotors_DriveStickButton->WhenPressed(new InvertMotorsFalse());

	turnXdegrees_DriveStickButton = new JoystickButton(driveStick, 5);
	turnXdegrees_DriveStickButton->WhenPressed(new TurnXDegrees());
	
	solenoidOut_DriveStickButton = new JoystickButton(driveStick, 7);
	solenoidOut_DriveStickButton->WhenPressed(new SolenoidOut());
	solenoidIn_DriveStickButton = new JoystickButton(driveStick, 8);
	solenoidIn_DriveStickButton->WhenPressed(new SolenoidIn());
	
	switchCam_DriveStickButton = new JoystickButton(driveStick, 9);
	switchCam_DriveStickButton->WhenPressed(new SwitchCam());
	
	//shootStick Button Commands
	shoot_ShootStickTrigger = new JoystickButton(shootStick, 1);
	shoot_ShootStickTrigger->WhenPressed(new Shoot());
	
	intake_ShootStickButton = new JoystickButton(shootStick, 2);
	intake_ShootStickButton->WhenPressed(new Intake());
	
	switchCam_ShootStickButton = new JoystickButton(shootStick, 3);
	switchCam_ShootStickButton->WhenPressed(new SwitchCam());
	
	adjustArmUpEncoder_ShootStickButton = new JoystickButton(shootStick, 5);
	adjustArmUpEncoder_ShootStickButton->WhenPressed(new AdjustArmUpEncoder());
	
	adjustArmDownEncoder_ShootStickButton = new JoystickButton(shootStick, 6);
	adjustArmDownEncoder_ShootStickButton->WhenPressed(new AdjustArmDownEncoder());
	
	solenoidOut_ShootStickButton = new JoystickButton(shootStick, 10);
	solenoidOut_ShootStickButton->WhenPressed(new SolenoidOut());
	
	solenoidIn_ShootStickButton = new JoystickButton(shootStick, 11);
	solenoidOut_ShootStickButton->WhenPressed(new SolenoidIn());
	
}



