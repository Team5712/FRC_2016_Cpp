//Finished

#include "StopShooter.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void StopShooter::StopShooter() : Command("StopShooter")
{
	Requires(Robot::shooterSystem);
}

void StopShooter::Initialize()
{
	std::cout << "StopShooter has initialized";
}

void StopShooter::Execute()
{
	Robot::shooterSystem->StopShooter();
}

bool StopShooter::IsFinished()
{
	return Robot::shooterSystem->IsStopped();
}

void StopShooter::End()
{
	
}

void StopShooter::Interrupted()
{
	std::cout << "StopShooter was interrupted!";
	End();
}

