#ifndef Intake_H
#define Intake_H

#include "../CommandBase.h"
#include "WPILib.h"

class Intake: public CommandBase
{
public:
	Intake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
