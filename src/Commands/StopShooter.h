#ifndef StopShooter_H
#define StopShooter_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopShooter: public CommandBase
{
public:
	StopShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

