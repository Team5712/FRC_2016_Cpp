#ifndef SolenoidIn_H
#define SolenoidIn_H

#include "WPILib.h"

class SolenoidIn: public Command
{
public:
	SolenoidIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif

