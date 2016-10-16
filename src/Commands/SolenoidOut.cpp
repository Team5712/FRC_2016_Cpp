#include "SolenoidOut.h"


void SolenoidOut::SolenoidOut() : Command("SolenoidOut")
{
	Requires(Robot::pneumaticSystem);
}

void SolenoidOut::Initialize()
{
	std::cout << "SolenoidOut has initialized";
	SetTimeout(0.5);
}

void SolenoidOut::Execute()
{
	Robot::pneumaticSystem->Out();
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
