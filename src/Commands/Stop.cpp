//Finished

#include "Stop.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void Stop::Stop() : CommandBase("Stop")
{
	Requires(Robot::DriveSystem);
}

void Stop::Initialize()
{
	std::cout << "Stop has initialized";
}

void Stop::Execute()
{
	Robot::DriveSystem::stop();
}

bool Stop::IsFinished()
{
	return Robot::DriveSystem::isStopped();
}

void Stop::End()
{
	Robot::DriveSystem::stopArm();
}

void Stop::Interrupted()
{
	std::cout << "Stop was interrupted!";
	End();
}

