#include "CommandBase.h"

CommandBase::ComandBase(const char *name) : CommandBase(name)
{
	//You guessed it, I have no idea what this function is for
}

CommandBase::CommandBase : CommandBase()
{
	//Likewise as above
}

//This stuff makes sense:
DriveSystem* CommandBase::driveSystem = NULL;
ShooterSystem* CommandBase::shooterSystem = NULL;
PneumaticSystem* CommandBase::pneumaticSystem = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init()
{
	driveSystem = new DriveSystem();
	shooterSystem = new ShooterSystem();
	pneumaticSystem = new PneumaticSystem();
	oi = new OI();
}
