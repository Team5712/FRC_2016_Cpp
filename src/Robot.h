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

class Robot : public IterativeRobot
{
public:
	// *** Methods ***
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

	// *** Objects ***
	static OI *oi;
	LiveWindow *window;

	// Subsystems
	static DriveSystem *driveSystem;
	static PneumaticSystem *pneumaticSystem;
	static ShooterSystem *shooterSystem;

	// Commands / CommandGroups
	CommandGroup *autonomousCommand;

	// Autonomous
	SendableChooser *defenseChooser, *positionChooser, *shootChooser;

	// *** Variables ***
	static bool IS_COMPETITION_ROBOT;

	// Camera
	int sessionFront;
	Image frame;

private:
	// *** Methods ***
	void AddAutoOptions(SendableChooser *, string);

	// *** Objects ***


	// *** Variables ***

	// Autonomous
	double angleSelected;
	string defenseSelected;
	int positionSelected;
	bool willShoot;



};


#endif
