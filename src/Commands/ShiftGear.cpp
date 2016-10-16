//Finished

#include "ShiftGear.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void ShiftGear::ShiftGear() : Command("ShiftGear")
{
	Requires(Robot::PneumaticSystem);
}

void ShiftGear::Initialize()
{
	std::cout << "ShiftGear has initialized";
}

void ShiftGear::Execute()
{
	Robot::PneumaticSystem->shiftHigh();
}

bool ShiftGear::IsFinished()
{
	return false;
}

void ShiftGear::End()
{
	Robot::PneumaticSystem->shiftLow();
}

void ShiftGear::Interrupted()
{
	std::cout << "AdjustArmUpEncoder was interrupted!";
	End();
}
