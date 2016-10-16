#ifndef ShiftGear_H
#define ShiftGear_H

#include "../Command.h"
#include "WPILib.h"

class ShiftGear: public Command
{
public:
	ShiftGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif
