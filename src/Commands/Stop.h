#ifndef Stop_H
#define Stop_H

#include "../Command.h"
#include "WPILib.h"

class Stop: public Command
{
public:
	Stop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

