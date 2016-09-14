#include "Intake.h"
#include "WPILib.h"
#include "../CommandBase.h"

#include <iostream>

void Intake::Intake() : CommandBase("Intake")
{
	Requires(Robot::ShooterSystem);
	SetTimeout(1);
}

void Intake::Initialize()
{
	std::cout << "Intake has initialized";
}

void Intake::Execute()
{
	Robot::ShooterSystem::intake();
}

bool Intake::IsFinished()
{
	return Robot::ShooterSystem::isTimedOut();
}

void Intake::End()
{
	Robot::ShooterSystem::stopShooter();
}

void Intake::Interrupted()
{
	std::cout << "Intake was interrupted!";
	End();
}

