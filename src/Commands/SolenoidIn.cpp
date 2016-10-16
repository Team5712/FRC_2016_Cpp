//Finished

#include "SolenoidIn.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void SolenoidIn::SolenoidIn() : Command("SolenoidIn")
{
	Requires(Robot::pneumaticSystem);
}

void SolenoidIn::Initialize()
{
	std::cout << "SolenoidIn has initialized";
	SetTimeout(0.5);
}

void SolenoidIn::Execute()
{
	Robot::pneumaticSystem->In();
}

bool SolenoidIn::IsFinished()
{
	return IsTimedOut();
}

void SolenoidIn::End()
{
	
}

void SolenoidIn::Interrupted()
{
	std::cout << "SolenoidIn was interrupted!";
	End();
}

