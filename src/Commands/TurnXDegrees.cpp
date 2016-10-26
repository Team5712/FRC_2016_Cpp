//Finished

#include "TurnXDegrees.h"
#include "WPILib.h"

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
	Robot::driveSystem->TurnXDegrees();
}

bool TurnXDegrees::IsFinished()
{
	return Robot::driveSystem->IsTurnedX();
}

void TurnXDegrees::End()
{
	Robot::driveSystem->Stop();
}

void TurnXDegrees::Interrupted()
{
	std::cout << "TurnXDegrees was interrupted!";
	End();
}

