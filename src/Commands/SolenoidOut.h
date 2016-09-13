#ifndef SolenoidOut_H
#define SolenoidOut_H

#include "../CommandBase.h"
#include "WPILib.h"

class SolenoidOut: public CommandBase
{
public:
	SolenoidOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

