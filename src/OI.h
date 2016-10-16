#ifndef OI_H
#define OI_H

#include "WPILib.h"


class OI
{

public:
	OI();

	// Joysticks
	Joystick *driveStick;
	Joystick *shootStick;

	// Buttons
	// DriveStick (Driver / Joystick 1)
	Button *shiftGear_DriveStickTrigger;

	Button *invertMotors_DriveStickButton;
	Button *normalizeMotors_DriveStickButton;

	Button *turnXdegrees_DriveStickButton;

	Button *solenoidOut_DriveStickButton;
	Button *solenoidIn_DriveStickButton;

	// ShootStick (Drive / Joystick 2)
	Button *shoot_ShootStickTrigger;
	Button *intake_ShootStickButton;

	Button *adjustArmUpEncoder_ShootStickButton;
	Button *adjustArmDownEncoder_ShootStickButton;

	Button *solenoidOut_ShootStickButton;
	Button *solenoidIn_ShootStickButton;


private:
	

};

#endif
