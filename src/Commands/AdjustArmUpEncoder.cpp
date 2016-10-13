//Finished

#include "AdjustArmUpEncoder.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void AdjustArmUpEncoder::AdjustArmUpEncoder() : Command("AdjustArmUpEncoder")
{
	Requires(Robot::ShooterSystem);
}

void AdjustArmUpEncoder::Initialize()
{
	std::cout << "AdjustArmUpEncoder has initialized";
}

void AdjustArmUpEncoder::Execute()
{
	Robot::ShooterSystem->armUp();
}

bool AdjustArmUpEncoder::IsFinished()
{
	return Robot::ShooterSystem->isUp();
}

void AdjustArmUpEncoder::End()
{
	Robot::ShooterSystem->stopArm();
}

void AdjustArmUpEncoder::Interrupted()
{
	std::cout << "AdjustArmUpEncoder was interrupted!";
	End();
}
