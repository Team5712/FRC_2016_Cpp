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

void ShooterSystem::ResetShooterEncoder()
{
	shooterEncoder.reset();
}

void ShooterSystem::ArmDown()
{
	shooter.set(-0.25);
}

bool ShooterSystem::IsDownAutonomous()
{
	if(shooterEncoder.get() > 1400)
	{
		return true;
	} else
	{
		return false;
	}
}

bool ShooterSystem::IsDown()
{
	if(shooterEncoder.get() > 0)
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::ArmUp()
{
	shooter.set(0.25);
}

bool ShooterSystem::IsUpAutonomous()
{
	if(shooterEncoder.get() < -10)
	{
		return true;
	} else
	{
		return false;
	}
}

bool ShooterSystem::IsUp()
{
	if(shooterEncoder.get() < shootTickGoal)
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::StopArm()
{
	shooter.set(0.0);
}

void ShooterSystem::Intake()
{
	shooterL.set(-.5);
	shooterR.set(.5);
}

void ShooterSystem::StopShooter()
{
	shooterL.set(0); //stops the left shooting motor
	shooterR.set(0); //stops the right shooting motor
}

bool ShooterSystem::IsStopped()
{
	if((shooterL.get() == 0) && (shooterR.get() == 0))
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::Shoot()
{
	shooterL.set(.5);
	shooterR.set(-.5);
}



