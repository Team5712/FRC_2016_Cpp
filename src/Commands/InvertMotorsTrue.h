#ifndef InvertMotorsTrue_H
#define InvertMotorsTrue_H

#include "../Command.h"
#include "WPILib.h"

class InvertMotorsTrue: public Command
{
public:
	InvertMotorsTrue();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif

