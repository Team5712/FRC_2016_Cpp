//Finished

#include "InvertMotorsTrue.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void InvertMotorsTrue::InvertMotorsTrue() : CommandBase("InvertMotorsTrue")
{
	Requires(Robot::DriveSystem);
}

void InvertMotorsTrue::Initialize()
{
	std::cout << "InvertMotorsTrue has initialized";
	Robot::DriveSystem::invertMotorsTrue();
}

void InvertMotorsTrue::Execute()
{
	
}

bool InvertMotorsTrue::IsFinished()
{
	return true;
}

void InvertMotorsTrue::End()
{
	
}

void InvertMotorsTrue::Interrupted()
{
	std::cout << "InvertMotorsTrue was interrupted!";
	End();
}

