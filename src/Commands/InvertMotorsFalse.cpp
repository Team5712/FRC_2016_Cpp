//Finished

#include "InvertMotorsFalse.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void InvertMotorsFalse::InvertMotorsFalse() : CommandBase("InvertMotorsFalse")
{
	Requires(Robot::DriveSystem);
}

void InvertMotorsFalse::Initialize()
{
	std::cout << "InvertMotorsFalse has initialized";
	Robot::DriveSystem::invertMotorsFalse();
}

void InvertMotorsFalse::Execute()
{
	
}

bool InvertMotorsFalse::IsFinished()
{
	return true;
}

void InvertMotorsFalse::End()
{
	
}

void InvertMotorsFalse::Interrupted()
{
	std::cout << "InvertMotorsFalse was interrupted!";
	End();
}
