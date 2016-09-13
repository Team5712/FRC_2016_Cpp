#ifndef Stop_H
#define Stop_H

#include "../CommandBase.h"
#include "WPILib.h"

class Stop: public CommandBase
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

