//Finished

#include "RaiseArmAutonomous.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void RaiseArmAutonomous::RaiseArmAutonomous() : Command("RaiseArmAutonomous")
{
	Requires(Robot::shooterSystem);
}

void RaiseArmAutonomous::Initialize()
{
	std::cout << "RaiseArmAutonomous has initialized";
}

void RaiseArmAutonomous::Execute()
{
	Robot::shooterSystem->ArmUp();
}

bool RaiseArmAutonomous::IsFinished()
{
	return Robot::shooterSystem->IsUpAutonomous();
}

void RaiseArmAutonomous::End()
{
	Robot::shooterSystem->StopArm();
}

void RaiseArmAutonomous::Interrupted()
{
	std::cout << "RaiseArmAutonomous was interrupted!";
	End();
}
