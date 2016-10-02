#include "ShooterSystem.h"
#include "../RobotMap.h"


ShooterSystem::ShooterSystem()
{
	
	shooterTickGoal = 10 * -140; //tick to degree ratio (degrees/tick) * angle desired

	shooterR = new VictorSP(RobotMap.SHOOTER_RIGHT_MOTOR);
	shooterL = new VictorSP(RobotMap.SHOOTER_LEFT_MOTOR);

	shooterEncoder = new Encoder(RobotMap.SHOOTER_ENCODER_A, RobotMap.SHOOTER_ENCODER_B, false, Encoder.EncodingType.k4X);

	shooter = new VictorSP(RobotMap.SHOOTER_LIFT_MOTOR);
}

void ShooterSystem::InitDefaultCommand()
{

}

void display()
{
	SmartDashboard.putNumber("Left Shooter Output", shooterL.get());
	SmartDashboard.putNumber("Right Shooter Output", shooterR.get());
	
	SmartDashboard.putNumber("Shooter Encoder", shooterEncoder.get());
}

void resetShooterEncoder()
{
	shooterEncoder.reset();
}

void armDown()
{
	shooter.set(-0.25);
}

bool isDownAutonomous()
{
	if(shooterEncoder.get() > 1400)
	{
		return true;
	} else
	{
		return false;
	}
}

bool isDown()
{
	if(shooterEncoder.get() > 0)
	{
		return true;
	} else
	{
		return false;
	}
}

void armUp()
{
	shooter.set(0.25);
}

bool isUpAutonomous()
{
	if(shooterEncoder.get() < -10)
	{
		return true;
	} else
	{
		return false;
	}
}

bool isUp()
{
	if(shooterEncoder.get() < shootTickGoal)
	{
		return true;
	} else
	{
		return false;
	}
}

void stopArm()
{
	shooter.set(0.0);
}

void intake()
{
	shooterL.set(-.5);
	shooterR.set(.5);
}

void stopShooter()
{
	shooterL.set(0); //stops the left shooting motor
	shooterR.set(0); //stops the right shooting motor
}

bool isStopped()
{
	if((shooterL.get() == 0) && (shooterR.get() == 0))
	{
		return true;
	} else
	{
		return false;
	}
}

void shoot()
{
	shooterL.set(.5);
	shooterR.set(-.5);
}



