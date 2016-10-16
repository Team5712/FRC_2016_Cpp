//Finished

#include "LowerArmAutonomous.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void LowerArmAutonomous::LowerArmAutonomous() : Command("LowerArmAutonomous")
{
	Requires(Robot::shooterSystem);
}

void LowerArmAutonomous::Initialize()
{
	std::cout << "LowerArmAutonomous has initialized";
}

void LowerArmAutonomous::Execute()
{
	Robot::shooterSystem->ArmDown();
}

bool LowerArmAutonomous::IsFinished()
{
	return Robot::shooterSystem->IsDownAutonomous();
}

void LowerArmAutonomous::End()
{
	Robot::shooterSystem->StopArm();
	Robot::shooterSystem->ResetShooterEncoder();
}

void LowerArmAutonomous::Interrupted()
{
	std::cout << "LowerArmAutonomous was interrupted!";
	End();
}
