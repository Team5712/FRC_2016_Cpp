//Finished

#include "DriveFowardEncoders.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void DriveFowardEncoders::DriveFowardEncoders() : CommandBase("DriveFowardEncoders")
{
	Requires(Robot::DriveSystem);
}

void DriveFowardEncoders::Initialize()
{
	std::cout << "DriveFowardEncoders has initialized";
}

void DriveFowardEncoders::Execute()
{
	Robot::DriveSystem->driveStraightForward();
}

bool DriveFowardEncoders::IsFinished()
{
	return Robot::DriveSystem->isUnderLowbar();
}

void DriveFowardEncoders::End()
{
	Robot::DriveSystem->stop();
}

void DriveFowardEncoders::Interrupted()
{
	std::cout << "DriveFowardEncoders was interrupted!";
	End();
}
