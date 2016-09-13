//Finished

#include "SolenoidIn.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void SolenoidIn::SolenoidIn() : CommandBase("SolenoidIn")
{
	Requires(Robot::PneumaticSystem);
}

void SolenoidIn::Initialize()
{
	std::cout << "SolenoidIn has initialized";
	//'setTimeout(0.5)' do not know C++ equivelant
}

void SolenoidIn::Execute()
{
	Robot::PneumaticSystem::in();
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

