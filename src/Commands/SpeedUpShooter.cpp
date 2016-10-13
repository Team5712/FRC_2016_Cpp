//Finished

#include "SpeedUpShooter.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void SpeedUpShooter::SpeedUpShooter() : Command("SpeedUpShooter")
{
	Requires(Robot::ShooterSystem);
	SetTimeout(1);
}

void SpeedUpShooter::Initialize()
{
	std::cout << "SpeedUpShooter has initialized";
}

void SpeedUpShooter::Execute()
{
	Robot::ShooterSystem->shoot();
}

bool SpeedUpShooter::IsFinished()
{
	return Robot::ShooterSystem->IsTimedOut();
}

void SpeedUpShooter::End()
{
	
}

void SpeedUpShooter::Interrupted()
{
	std::cout << "SpeedUpShooter was interrupted!";
	End();
}

