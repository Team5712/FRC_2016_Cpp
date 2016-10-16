#include "Shoot.h"



Shoot::Shoot()
{
	AddSequential(new SpeedUpShooter());
	AddSequential(new SolenoidOut());
	AddParallel(new StopShooter());
	AddSequential(new SolenoidIn());
}
