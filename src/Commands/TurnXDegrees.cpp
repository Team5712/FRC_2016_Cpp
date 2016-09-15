//Finished

#include "TurnXDegrees.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void TurnXDegrees::TurnXDegrees() : CommandBase("TurnXDegrees")
{
	Requires(Robot::DriveSystem);
}

void TurnXDegrees::Initialize()
{
	std::cout << "TurnXDegrees has initialized";
}

void TurnXDegrees::Execute()
{
	Robot::ShooterSystem->turnXDegrees();
}

bool TurnXDegrees::IsFinished()
{
	return Robot::ShooterSystem->isTurnedX();
}

void TurnXDegrees::End()
{
	Robot::ShooterSystem->stop();
}

void TurnXDegrees::Interrupted()
{
	std::cout << "TurnXDegrees was interrupted!";
	End();
}

