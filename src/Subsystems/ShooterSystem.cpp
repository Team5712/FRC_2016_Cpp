#include "ShooterSystem.h"
#include "../RobotMap.h"


ShooterSystem::ShooterSystem()
{
	
	shooterTickGoal = 10 * -140; //tick to degree ratio (degrees/tick) * angle desired

	shooterR = new VictorSP(RobotMap::SHOOTER_RIGHT_MOTOR);
	shooterL = new VictorSP(RobotMap::SHOOTER_LEFT_MOTOR);

	shooterEncoder = new Encoder(RobotMap::SHOOTER_ENCODER_A, RobotMap::SHOOTER_ENCODER_B, false, Encoder::EncodingType::k4X);

	shooterLift = new VictorSP(RobotMap::SHOOTER_LIFT_MOTOR);
}

void ShooterSystem::InitDefaultCommand()
{

}

void ShooterSystem::Display()
{
	SmartDashboard::PutNumber("Left Shooter Output", shooterL.Get());
	SmartDashboard::PutNumber("Right Shooter Output", shooterR.Get());
	
	SmartDashboard::PutNumber("Shooter Encoder", shooterEncoder.Get());
}

void ShooterSystem::ResetShooterEncoder()
{
	shooterEncoder.Reset();
}

void ShooterSystem::ArmDown()
{
	shooterLift.Set(-0.25);
}

void ShooterSystem::ArmUp()
{
	shooterLift.Set(0.25);
}

bool ShooterSystem::IsDownAutonomous()
{
	if(shooterEncoder.Get() > 1400)
	{
		return true;
	} else
	{
		return false;
	}
}

bool ShooterSystem::IsUpAutonomous()
{
	if(shooterEncoder.Get() < -10)
	{
		return true;
	} else
	{
		return false;
	}
}

bool ShooterSystem::IsDown()
{
	if(shooterEncoder.Get() > 0)
	{
		return true;
	} else
	{
		return false;
	}
}

bool ShooterSystem::IsUp()
{
	if(shooterEncoder.Get() < shooterTickGoal)
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::StopArm()
{
	shooterLift.Set(0.0);
}

void ShooterSystem::Intake()
{
	shooterL.Set(-.5);
	shooterR.Set(.5);
}

void ShooterSystem::StopShooter()
{
	shooterL.Set(0); //stops the left shooting motor
	shooterR.Set(0); //stops the right shooting motor
}

bool ShooterSystem::IsStopped()
{
	if((shooterL.Get() == 0) && (shooterR.Get() == 0))
	{
		return true;
	} else
	{
		return false;
	}
}

void ShooterSystem::Shoot()
{
	shooterL.Set(.5);
	shooterR.Set(-.5);
}



