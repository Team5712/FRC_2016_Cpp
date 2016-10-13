#ifndef TurnXDegrees_H
#define TurnXDegrees_H

#include "../Command.h"
#include "WPILib.h"

class TurnXDegrees: public Command
{
public:
	TurnXDegrees();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif

