#include "AdjustArmDownEncoder.h"


AdjustArmDownEncoder::AdjustArmDownEncoder()
{
	Requires(Robot::shooterSystem);
}

void AdjustArmDownEncoder::Initialize()
{
	
}

void AdjustArmDownEncoder::Execute()
{
	Robot::shooterSystem->ArmDown();
}

bool AdjustArmDownEncoder::IsFinished()
{
	return Robot::shooterSystem->IsDown();
}

void AdjustArmDownEncoder::End()
{
	Robot::shooterSystem->StopArm();
}

void AdjustArmDownEncoder::Interrupted()
{
	std::cout << "Shooter arm failed to adjust!";
	End();
}
