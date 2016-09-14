#ifndef TurnXDegrees_H
#define TurnXDegrees_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnXDegrees: public CommandBase
{
public:
	TurnXDegrees();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

