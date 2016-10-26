#ifndef SolenoidOut_H
#define SolenoidOut_H

#include "WPILib.h"

class SolenoidOut: public Command
{
public:
	SolenoidOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif

