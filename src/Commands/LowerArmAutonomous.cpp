//Finished

#include "LowerArmAutonomous.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void LowerArmAutonomous::LowerArmAutonomous() : Command("LowerArmAutonomous")
{
	Requires(Robot::ShooterSystem);
}

void LowerArmAutonomous::Initialize()
{
	std::cout << "LowerArmAutonomous has initialized";
}

void LowerArmAutonomous::Execute()
{
	Robot::ShooterSystem->armDown();
}

bool LowerArmAutonomous::IsFinished()
{
	return Robot::ShooterSystem->isDownAutonomous();
}

void LowerArmAutonomous::End()
{
	Robot::ShooterSystem->stopArm();
	Robot::ShooterSystem->resetShooterEncoder();
}

void LowerArmAutonomous::Interrupted()
{
	std::cout << "LowerArmAutonomous was interrupted!";
	End();
}
