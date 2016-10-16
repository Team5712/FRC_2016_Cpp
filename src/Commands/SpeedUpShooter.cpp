//Finished

#include "SpeedUpShooter.h"


void SpeedUpShooter::SpeedUpShooter() : Command("SpeedUpShooter")
{
	Requires(Robot::shooterSystem);
	SetTimeout(1);
}

void SpeedUpShooter::Initialize()
{
	std::cout << "SpeedUpShooter has initialized";
}

void SpeedUpShooter::Execute()
{
	Robot::shooterSystem->Shoot();
}

bool SpeedUpShooter::IsFinished()
{
	return IsTimedOut();
}

void SpeedUpShooter::End()
{
	
}

void SpeedUpShooter::Interrupted()
{
	std::cout << "SpeedUpShooter was interrupted!";
	End();
}

