#ifndef ROBOT_H
#define ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "OI.h"

#include "string"

// Subsystems
#include "Subsystems/DriveSystem.h"
#include "Subsystems/PneumaticSystem.h"
#include "Subsystems/ShooterSystem.h"


using namespace std;

class Robot
{
public:
	// *** Methods ***
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();


	// *** Objects ***
	static OI * oi;
	LiveWindow * window;

	// Subsystems
	static DriveSystem * driveSystem;

	// Commands / CommandGroups
	CommandGroup * autonomousCommand;

	// Autonomous
	SendableChooser * defenseChooser, * positionChooser, * shootChooser;

	// *** Variables ***
	static bool IS_COMPETITION_ROBOT;

	// Camera
	int sessionFront;
	Image frame;

private:
	// *** Methods ***
	SendableChooser * addAutoOptions(SendableChooser *, string);

	// *** Objects ***


	// *** Variables ***

	// Autonomous
	double angleSelected;
	string defenseSelected;
	int positionSelected;
	bool willShoot;



};


#endif
