#include "../CommandBase.h";
#include "WPILibs.h";
#include "AdjustArmDownEncoder.h"

#include <iostream>

AdjustArmDownEncoder::AdjustArmDownEncoder() : CommandBase("AdjustArmDownEncoder")
{
	Requires(Robot::ShooterSystem);
}

void AdjustArmDownEncoder::Initialize()
{
	
}

void AdjustArmDownEncoder::Execute()
{
	Robot::ShooterSystem::armDown();
}

bool AdjustArmDownEncoder::IsFinished()
{
	Robot::ShooterSystem::isDown();
}

void AdjustArmDownEncoder::End()
{
	Robot::ShooterSystem::armStop();
}

void AdjustArmDownEncoder::Interrupted()
{
	std::cout << "Shooter arm failed to adjust!";
	End();
}
