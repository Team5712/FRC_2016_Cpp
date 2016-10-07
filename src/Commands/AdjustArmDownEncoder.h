#ifndef AdjustArmDownEncoder_H
#define AdjustArmDownEncoder_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AdjustArmDownEncoder: public Command
{
public:
	AdjustArmDownEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif
