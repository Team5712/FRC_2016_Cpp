#ifndef SpeedUpShooter_H
#define SpeedUpShooter_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpeedUpShooter: public CommandBase
{
public:
	SpeedUpShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

