//Finished

#include "DriveForwardEncoders.h"


void DriveForwardEncoders::DriveForwardEncoders() : Command("DriveFowardEncoders")
{
	Requires(Robot::driveSystem);
}

void DriveForwardEncoders::Initialize()
{
	std::cout << "DriveFowardEncoders has initialized";
}

void DriveForwardEncoders::Execute()
{
	Robot::driveSystem->DriveStraightForward();
}

bool DriveForwardEncoders::IsFinished()
{
	return Robot::driveSystem->IsUnderLowbar();
}

void DriveForwardEncoders::End()
{
	Robot::driveSystem->Stop();
}

void DriveForwardEncoders::Interrupted()
{
	std::cout << "DriveFowardEncoders was interrupted!";
	End();
}
