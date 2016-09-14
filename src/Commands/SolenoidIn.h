#ifndef SolenoidIn_H
#define SolenoidIn_H

#include "../CommandBase.h"
#include "WPILib.h"

class SolenoidIn: public CommandBase
{
public:
	SolenoidIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

