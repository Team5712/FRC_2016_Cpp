#include "../CommandBase.h";
#include "WPILibs.h";

#include <iostream>

AdjustArmDownEncoder::AdjustArmDownEncoder() : CommandBase("AdjustArmDownEncoder")
{
	Requires(Robot::shooterSubsystem);
}

void AdjustArmDownEncoder::Initialize()
{
	
}

void AdjustArmDownEncoder::Execute()
{
	Robot::ShooterSubsystem.armDown();
}

bool AdjustArmDownEncoder::IsFinished()
{
	Robot::ShooterSubsystem.isDown();
}

void AdjustArmDownEncoder::End()
{
	Robot::ShooterSubsystem.armStop();
}

void AdjustArmDownEncoder::Interrupted()
{
	std::cout << "Shooter arm failed to adjust!";
	End();
}
