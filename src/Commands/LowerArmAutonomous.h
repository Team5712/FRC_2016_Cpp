#ifndef LowerArmAutonomous_H
#define LowerArmAutonomous_H

#include "WPILib.h"

class LowerArmAutonomous: public Command
{
public:
	LowerArmAutonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif
