#ifndef InvertMotorsTrue_H
#define InvertMotorsTrue_H

#include "../CommandBase.h"
#include "WPILib.h"

class InvertMotorsTrue: public CommandBase
{
public:
	InvertMotorsTrue();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif

