#ifndef LowerArmAutonomous_H
#define LowerArmAutonomous_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowerArmAutonomous: public CommandBase
{
public:
	LowerArmAutonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
