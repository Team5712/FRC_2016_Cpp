//Finished

#include "ShiftGear.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void ShiftGear::ShiftGear() : Command("ShiftGear")
{
	Requires(Robot::pneumaticSystem);
}

void ShiftGear::Initialize()
{
	std::cout << "ShiftGear has initialized";
}

void ShiftGear::Execute()
{
	Robot::pneumaticSystem->ShiftHigh();
}

bool ShiftGear::IsFinished()
{
	return false;
}

void ShiftGear::End()
{
	Robot::pneumaticSystem->ShiftLow();
}

void ShiftGear::Interrupted()
{
	std::cout << "AdjustArmUpEncoder was interrupted!";
	End();
}
