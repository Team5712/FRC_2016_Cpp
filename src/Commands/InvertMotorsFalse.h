#ifndef InvertMotorsFalse_H
#define InvertMotorsFalse_H

#include "../CommandBase.h"
#include "WPILib.h"

class InvertMotorsFalse: public CommandBase
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
