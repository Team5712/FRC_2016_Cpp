#ifndef InvertMotorsFalse_H
#define InvertMotorsFalse_H

#include "../Command.h"
#include "WPILib.h"

class InvertMotorsFalse: public Command
{
public:
	InvertMotorsFalse();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
