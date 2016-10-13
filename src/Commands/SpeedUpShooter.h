#ifndef SpeedUpShooter_H
#define SpeedUpShooter_H

#include "../Command.h"
#include "WPILib.h"

class SpeedUpShooter: public Command
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

