//Finished

#include "RaiseArmAutonomous.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void RaiseArmAutonomous::RaiseArmAutonomous() : CommandBase("RaiseArmAutonomous")
{
	Requires(Robot::ShooterSystem);
}

void RaiseArmAutonomous::Initialize()
{
	std::cout << "RaiseArmAutonomous has initialized";
}

void RaiseArmAutonomous::Execute()
{
	Robot::ShooterSystem::armUp();
}

bool RaiseArmAutonomous::IsFinished()
{
	return Robot::ShooterSystem::isUpAutonomous();
}

void RaiseArmAutonomous::End()
{
	Robot::ShooterSystem::stopArm();
}

void RaiseArmAutonomous::Interrupted()
{
	std::cout << "RaiseArmAutonomous was interrupted!";
	End();
}
