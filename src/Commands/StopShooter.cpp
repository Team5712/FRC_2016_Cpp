//Finished

#include "StopShooter.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void StopShooter::StopShooter() : Command("StopShooter")
{
	Requires(Robot::ShooterSystem);
}

void StopShooter::Initialize()
{
	std::cout << "StopShooter has initialized";
}

void StopShooter::Execute()
{
	Robot::ShooterSystem->stopShooter();
}

bool StopShooter::IsFinished()
{
	return Robot::ShooterSystem->isStopped();
}

void StopShooter::End()
{
	
}

void StopShooter::Interrupted()
{
	std::cout << "StopShooter was interrupted!";
	End();
}

