#ifndef RaiseArmAutonomous_H
#define RaiseArmAutonomous_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseArmAutonomous: public CommandBase
{
public:
	RaiseArmAutonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
