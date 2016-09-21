#include "RobotMap.h"
#include "AHRS.h"
#include "Encoder.h"
#include "RobotDrive.h"
#include "SerialPort.h"
#include "VictorSP.h"
#include "Subystem.h"
#include "SmartDashboard.h"

class Robot : public ItertatveRobot
{
public:

static boolean IS_COMPETITION_ROBOT;
	
static DriveSubsystem driveSubsystem = new DriveSubsystem();	
static ShooterSubsystem shooterSubsystem = new ShooterSubsystem();
static PneumaticSubsystem pneumaticSubsystem = new PneumaticSubsystem();
	
static OI oi;
	
    //Autonomous commands
    CommandGroup autonomousSelected;
    double angleSelected;
    
    //Autonomous Selector
    SendableChooser autoChooser, angleChooser;
    
    //Camera Variables
    int sessionFront;
    Image frame;

	void RobotInit()
	{
	oi = new OI(); 
		
		autoChooser = new SendableChooser();
		autoChooser.addDefault("Lowbar", new LowbarAutonomous());
		autoChooser.addObject("Moat", new MoatAutonomous());
		SmartDashboard.putData("Autonomous Mode Chooser", autoChooser);
		
		angleChooser = new SendableChooser();
		angleChooser.addDefault("120", 120);
		angleChooser.addObject("150", 150);
		SmartDashboard.putData("Angle Chooser", angleChooser);
		
		pneumaticSubsystem.compressor.setClosedLoopControl(true);
		
		frame = NIVision.imaqCreateImage(NIVision.ImageType.IMAGE_RGB, 0);
		sessionFront = NIVision.IMAQdxOpenCamera("cam0", NIVision.IMAQdxCameraControlMode.CameraControlModeController);
		NIVision.IMAQdxConfigureGrab(sessionFront);
		
		driveSubsystem.resetGyro();
		driveSubsystem.resetDriveEncoders();
		shooterSubsystem.resetShooterEncoder();	
	}
	
	void AutonomousInit()
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
	
	void AutonomousPeriodic()
	{
	Scheduler.getInstance().run();
        
        driveSubsystem.display();
        shooterSubsystem.display();	
	}
	
	void TeleopInit()
	{
	if (autonomousSelected != null) autonomousSelected.cancel();
    	
    	driveSubsystem.resetDriveEncoders();
    	driveSubsystem.resetGyro();	
	}
	
	void TeleopPeriodic()
	{
	Scheduler.getInstance().run();
    	
    	driveSubsystem.drive.arcadeDrive(oi.driveStick);
    	shooterSubsystem.shooter.set(oi.shootStick.getRawAxis(1));
    	
    	driveSubsystem.display();
    	shooterSubsystem.display();
		
		NIVision.IMAQdxGrab(sessionFront, frame, 0);
		CameraServer.getInstance().setImage(frame);	
	}
}
