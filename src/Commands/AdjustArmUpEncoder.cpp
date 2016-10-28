//Finished

#include "AdjustArmUpEncoder.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void AdjustArmUpEncoder::AdjustArmUpEncoder() : Command("AdjustArmUpEncoder")
{
	Requires(Robot::shooterSystem);
}

void AdjustArmUpEncoder::Initialize()
{
	std::cout << "AdjustArmUpEncoder has initialized";
}

void AdjustArmUpEncoder::Execute()
{
	Robot::shooterSystem->ArmUp();
}

bool AdjustArmUpEncoder::IsFinished()
{
	return Robot::shooterSystem->IsUp();
}

void AdjustArmUpEncoder::End()
{
	Robot::shooterSystem->StopArm();
}

void AdjustArmUpEncoder::Interrupted()
{
	std::cout << "AdjustArmUpEncoder was interrupted!";
	End();
}
