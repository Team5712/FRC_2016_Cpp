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
	
	defenseChooser = new SendableChooser();
	AddAutoOptions(defenseChooser, "defense");

	pneumaticSystem->compressor.setClosedLoopControl(true);

	frame = NIVision.imaqCreateImage(NIVision.ImageType.IMAGE_RGB, 0);
	sessionFront = NIVision.IMAQdxOpenCamera("cam0", NIVision.IMAQdxCameraControlMode.CameraControlModeController);
	NIVision.IMAQdxConfigureGrab(sessionFront);

	driveSystem->ResetGyro();
	driveSubsystem.resetDriveEncoders();
	shooterSubsystem.resetShooterEncoder();
}

void Robot::AutonomousInit()
{
	System.out.println("Autonomous Selected: " + autoChooser.getSelected());
	System.out.println("Angle Selected: " + angleChooser.getSelected());

	pneumaticSubsystem.in();
	driveSubsystem.resetDriveEncoders();
	driveSubsystem.resetGyro();
	shooterSubsystem.resetShooterEncoder();
	
	autonomousSelected = (CommandGroup) autoChooser.getSelected();
	angleSelected = (int) angleChooser.getSelected();
	autonomousSelected.start();
}

void Robot::AutonomousPeriodic()
{
	Scheduler.getInstance().run();
	
	driveSubsystem.display();
	shooterSubsystem.display();
}

void Robot::TeleopInit()
{
	if (autonomousSelected != null) autonomousSelected.cancel()
	{
		driveSubsystem.resetDriveEncoders();
		driveSubsystem.resetGyro();
	}
}

void Robot::TeleopPeriodic()
{
	Scheduler.getInstance().run();
	
	driveSubsystem.drive.arcadeDrive(oi.driveStick);
	shooterSubsystem.shooter.set(oi.shootStick.getRawAxis(1));

	driveSubsystem.display();
	shooterSubsystem.display();

	NIVision.IMAQdxGrab(sessionFront, frame, 0);
	CameraServer.getInstance().setImage(frame);
}

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
	}

}

