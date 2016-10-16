//Finished

#include "InvertMotorsTrue.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void InvertMotorsTrue::InvertMotorsTrue() : Command("InvertMotorsTrue")
{
	Requires(Robot::driveSystem);
}

void InvertMotorsTrue::Initialize()
{
	std::cout << "InvertMotorsTrue has initialized";
	Robot::driveSystem->InvertMotorsTrue();
}

void InvertMotorsTrue::Execute()
{
	
}

bool InvertMotorsTrue::IsFinished()
{
	return false; // May cause a problem later...
}

void InvertMotorsTrue::End()
{
	
}

void InvertMotorsTrue::Interrupted()
{
	std::cout << "InvertMotorsTrue was interrupted!";
	End();
}

