#include "../CommandBase.h";
#include "WPILibs.h";

AdjustArmDownEncoder::AdjustArmDownEncoder() : CommandBase("AdjustArmDownEncoder")
{
	Requires(Robot::ShooterSubsystem);
}
