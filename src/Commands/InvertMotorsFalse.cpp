//Finished

#include "InvertMotorsFalse.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void InvertMotorsFalse::InvertMotorsFalse() : Command("InvertMotorsFalse")
{
	Requires(Robot::DriveSystem);
}

void InvertMotorsFalse::Initialize()
{
	std::cout << "InvertMotorsFalse has initialized";
	Robot::DriveSystem->invertMotorsFalse();
}

void InvertMotorsFalse::Execute()
{
	
}

bool InvertMotorsFalse::IsFinished()
{
	return false;
}

void InvertMotorsFalse::End()
{
	
}

void InvertMotorsFalse::Interrupted()
{
	std::cout << "InvertMotorsFalse was interrupted!";
	End();
}
