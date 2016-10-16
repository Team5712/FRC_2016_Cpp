#include "Robot.h"
//#include "RobotMap.h"
//#include "AHRS.h"
//#include "Encoder.h"
//#include "RobotDrive.h"
//#include "SerialPort.h"
//#include "VictorSP.h"


DriveSystem *Robot::driveSystem = 0;
PneumaticSystem *Robot::pneumaticSystem = 0;
ShooterSystem *Robot::shooterSystem = 0;

void Robot::RobotInit()
{
	driveSystem = new DriveSystem();
	pneumaticSystem = new PneumaticSystem();
	shooterSystem = new ShooterSystem();

	oi = new OI();
	window = LiveWindow::GetInstance();
	
	// Choosers - Defense
	defenseChooser = new SendableChooser();
	AddAutoOptions(defenseChooser, "defense");
	SmartDashboard::PutData("Defense Chooser", defenseChooser);

	// Choosers - Position
	positionChooser = new SendableChooser();
	AddAutoOptions(positionChooser, "position");
	SmartDashboard::PutData("Position Chooser", positionChooser);

	// Choosers - Shoot
	shootChooser = new SendableChooser();
	shootChooser->AddDefault("No Shoot", true); // Add the objects. Should the robot shoot or not in autonomous
	shootChooser->AddObject("No Shoot", false);
	SmartDashboard::PutData("Shoot Chooser", shootChooser);

	pneumaticSystem->compressor.SetClosedLoopControl(true);

//	frame = NIVision.imaqCreateImage(NIVision.ImageType.IMAGE_RGB, 0);
//	sessionFront = NIVision.IMAQdxOpenCamera("cam0", NIVision.IMAQdxCameraControlMode.CameraControlModeController);
//	NIVision.IMAQdxConfigureGrab(sessionFront);

	driveSystem->ResetGyro();
	driveSystem->ResetDriveEncoders();
	shooterSystem->ResetShooterEncoder();
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	cout << "Defense Selected: " << defenseChooser->GetSelected() << endl;
	cout << "Position Selected: " << positionChooser->GetSelected() << endl;

	pneumaticSystem->In();
	driveSystem->ResetDriveEncoders();
	driveSystem->ResetGyro();
	shooterSystem->ResetShooterEncoder();
	
//	autonomousSelected = (CommandGroup) autoChooser.getSelected();
//	angleSelected = (int) angleChooser.getSelected();
//	autonomousSelected.start();

	// These may need to be casted as string and int respectively
	defenseSelected = defenseChooser->GetSelected();
	positionSelected = positionChooser->GetSelected();
	willShoot = shootChooser->GetSelected();

	autonomousCommand = new DriveAutonomous(defenseSelected, positionSelected, willShoot);
	autonomousCommand->Start();

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
	
	driveSystem->Display();
	shooterSystem->Display();
}

void Robot::TeleopInit()
{
	// Single-line if statement:
	if(autonomousCommand != NULL) autonomousCommand->Cancel();
	driveSystem->ResetDriveEncoders();
	driveSystem->ResetGyro();
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
	
	driveSystem->drive.ArcadeDrive(oi->driveStick);
	shooterSystem->shooterLift.Set(oi->shootStick->GetRawAxis(1));

	driveSystem->Display();
	shooterSystem->Display();

//	NIVision.IMAQdxGrab(sessionFront, frame, 0);
//	CameraServer::GetInstance()->SetImage(frame);
}

void Robot::TestPeriodic()
{
	LiveWindow::GetInstance()->Run();
}


// Custom methods

void Robot::AddAutoOptions(SendableChooser *chooser, string optionSet)
{

	// Use proper English and capitalization for these names, as they will
	// be displayed on the SmartDashboard. Later, we can make these lower-case
	// and replace the spaces with underscores. This is basically to keep consistent
	// to programming naming
	const string defenses[] = {"Portcullis", "Cheval de Frise", // A
			"Ramparts", "Moat", // B
			"Drawbridge", "Sally Port", // C
			"Rock Wall", "Rough Terrain", // D
			"Low Bar", // Required
			"No Cross"};

	const int positions[] = {1, 2, 3, 4, 5};


	if(optionSet.compare("defense") == 0)
	{
		// Defenses
		for(int d = 0; d < sizeof(defenses); d++)
		{
			chooser->AddObject(defenses[d], defenses[d]);
		}
	} else
	{
		// Positions
		for(int p = 0; p < sizeof(positions); p++)
		{
			chooser->AddObject("Position #" << positions[p], positions[p]);
		}
	}

}

