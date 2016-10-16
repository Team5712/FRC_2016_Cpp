//Finished

#include "TurnXDegrees.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void TurnXDegrees::TurnXDegrees() : Command("TurnXDegrees")
{
	Requires(Robot::driveSystem);
}

void TurnXDegrees::Initialize()
{
	std::cout << "TurnXDegrees has initialized";
}

void TurnXDegrees::Execute()
{
	Robot::shooterSystem->TurnXDegrees();
}

bool TurnXDegrees::IsFinished()
{
	return Robot::shooterSystem->IsTurnedX();
}

void TurnXDegrees::End()
{
	Robot::shooterSystem->Stop();
}

void TurnXDegrees::Interrupted()
{
	std::cout << "TurnXDegrees was interrupted!";
	End();
}

