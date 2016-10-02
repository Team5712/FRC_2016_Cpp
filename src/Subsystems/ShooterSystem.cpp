#include "ShooterSystem.h"
#include "../RobotMap.h"


ShooterSystem::ShooterSystem()
{
	
	shooterTickGoal = 10 * -140; //tick to degree ratio (degrees/tick) * angle desired

	shooterR = new VictorSP(RobotMap::SHOOTER_RIGHT_MOTOR);
	shooterL = new VictorSP(RobotMap::SHOOTER_LEFT_MOTOR);

	shooterEncoder = new Encoder(RobotMap::SHOOTER_ENCODER_A, RobotMap.SHOOTER_ENCODER_B, false, Encoder.EncodingType.k4X);

	shooterLift = new VictorSP(RobotMap::SHOOTER_LIFT_MOTOR);
}

void ShooterSystem::InitDefaultCommand()
{

}

void ShooterSystem::Display()
{
	SmartDashboard::PutNumber("Left Shooter Output", shooterL.get());
	SmartDashboard::PutNumber("Right Shooter Output", shooterR.get());
	
	SmartDashboard::putNumber("Shooter Encoder", shooterEncoder.get());
}

void ShooterSystem::resetShooterEncoder()
{
	shooterEncoder.reset();
}

void ShooterSystem::armDown()
{
	shooter.set(-0.25);
}

bool ShooterSystem::isDownAutonomous()
{
	if(shooterEncoder.get() > 1400)
	{
		return true;
	} else
	{
		return false;
	}
}

bool ShooterSystem::isDown()
{
	if(shooterEncoder.get() > 0)
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::armUp()
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

bool ShooterSystem::isUp()
{
	if(shooterEncoder.get() < shootTickGoal)
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::stopArm()
{
	shooter.set(0.0);
}

void ShooterSystem::intake()
{
	shooterL.set(-.5);
	shooterR.set(.5);
}

void ShooterSystem::stopShooter()
{
	shooterL.set(0); //stops the left shooting motor
	shooterR.set(0); //stops the right shooting motor
}

bool ShooterSystem::isStopped()
{
	if((shooterL.get() == 0) && (shooterR.get() == 0))
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::shoot()
{
	shooterL.set(.5);
	shooterR.set(-.5);
}



