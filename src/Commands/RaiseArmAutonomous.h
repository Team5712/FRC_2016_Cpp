#ifndef RaiseArmAutonomous_H
#define RaiseArmAutonomous_H

#include "../Command.h"
#include "WPILib.h"

class RaiseArmAutonomous: public Command
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
