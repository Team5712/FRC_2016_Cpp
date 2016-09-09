#include "Shooter.h"

/*
||This title is pretty self explanitory
*/

Shooter::Shooter()
{
	AddSequential(new SpeedUpMotors());
	AddSequential(new SolenoidOut());
	AddParallel(new StopShooter());
	AddSequential(new SolenoidIn());
}
