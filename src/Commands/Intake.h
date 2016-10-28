#ifndef Intake_H
#define Intake_H

#include "WPILib.h"

class Intake: public Command
{
public:
	Intake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif
