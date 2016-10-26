//Finished

#include "Stop.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void Stop::Stop() : CommandBase("Stop")
{
	Requires(Robot::driveSystem);
}

void Stop::Initialize()
{
	std::cout << "Stop has initialized";
}

void Stop::Execute()
{
	Robot::driveSystem->Stop();
}

bool Stop::IsFinished()
{
	return Robot::driveSystem->IsStopped();
}

void Stop::End()
{
	Robot::driveSystem->Stop();
}

void Stop::Interrupted()
{
	std::cout << "Stop was interrupted!";
	End();
}

