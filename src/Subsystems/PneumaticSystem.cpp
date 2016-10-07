#include "PneumaticSystem.h"
#include "../RobotMap.h"


PneumaticSystem::PneumaticSystem()
{

	shifterSolenoid = new DoubleSolenoid(RobotMap::SHIFTER_SOLENOID_A, RobotMap::SHIFTER_SOLENOID_B);
	shooterSolenoid = new DoubleSolenoid(RobotMap::SHOOTER_SOLENOID_A, RobotMap::SHOOTER_SOLENOID_B);

	compressor = new Compressor(RobotMap::COMPRESSOR);
}

void PneumaticSystem::InitDefaultCommand()
{

}

void PneumaticSystem::ShiftHigh()
{
	shifterSolenoid.Set(DoubleSolenoid::Value::kForward);
}

void PneumaticSystem::ShiftLow()
{
	shifterSolenoid.Set(DoubleSolenoid::Value::kReverse);
}

void PneumaticSystem::In()
{
	shooterSolenoid.Set(DoubleSolenoid::Value::kReverse);
}

void PneumaticSystem::Out()
{
	shooterSolenoid.Set(DoubleSolenoid::Value::kForward);
}


