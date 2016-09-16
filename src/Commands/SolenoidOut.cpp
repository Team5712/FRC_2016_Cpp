#include "SolenoidOut.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void SolenoidOut::SolenoidOut() : CommandBase("SolenoidOut")
{
	Requires(Robot::PneumaticSystem);
}

void SolenoidOut::Initialize()
{
	std::cout << "SolenoidOut has initialized";
	SetTimeout(0.5);
}

void SolenoidOut::Execute()
{
	Robot::PneumaticSystem::out();
}

bool SolenoidOut::IsFinished()
{
	return IsTimedOut();
}

void SolenoidOut::End()
{
	
}

void SolenoidOut::Interrupted()
{
	std::cout << "SolenoidOut was interrupted!";
	End();
}
