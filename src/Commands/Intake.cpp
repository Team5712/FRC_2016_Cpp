#include "Intake.h"
#include "WPILib.h"
#include "../Command.h"

#include <iostream>

void Intake::Intake() : Command("Intake")
{
	Requires(Robot::shooterSystem);
	SetTimeout(1);
}

void Intake::Initialize()
{
	std::cout << "Intake has initialized";
}

void Intake::Execute()
{
	Robot::shooterSystem->Intake();
}

bool Intake::IsFinished()
{
	return IsTimedOut(); // May need to have Robot::shooterSystem->  in front of this
}

void Intake::End()
{
	Robot::shooterSystem->StopShooter();
}

void Intake::Interrupted()
{
	std::cout << "Intake was interrupted!";
	End();
}

