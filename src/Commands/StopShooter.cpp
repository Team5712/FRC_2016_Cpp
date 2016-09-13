//Finished

#include "StopShooter.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void StopShooter::StopShooter() : CommandBase("StopShooter")
{
	Requires(Robot::ShooterSystem);
}

void StopShooter::Initialize()
{
	std::cout << "StopShooter has initialized";
}

void StopShooter::Execute()
{
	Robot::ShooterSystem::stopShooter();
}

bool StopShooter::IsFinished()
{
	return Robot::ShooterSystem::isStopped();
}

void StopShooter::End()
{
	
}

void StopShooter::Interrupted()
{
	std::cout << "StopShooter was interrupted!";
	End();
}

