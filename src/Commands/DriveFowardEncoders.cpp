//Finished

#include "DriveFowardEncoders.h"


void DriveFowardEncoders::DriveFowardEncoders() : Command("DriveFowardEncoders")
{
	Requires(Robot::driveSystem);
}

void DriveFowardEncoders::Initialize()
{
	std::cout << "DriveFowardEncoders has initialized";
}

void DriveFowardEncoders::Execute()
{
	Robot::driveSystem->DriveStraightForward();
}

bool DriveFowardEncoders::IsFinished()
{
	return Robot::driveSystem->IsUnderLowbar();
}

void DriveFowardEncoders::End()
{
	Robot::driveSystem->Stop();
}

void DriveFowardEncoders::Interrupted()
{
	std::cout << "DriveFowardEncoders was interrupted!";
	End();
}
