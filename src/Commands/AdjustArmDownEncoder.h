#ifndef AdjustArmDownEncoder_H
#define AdjustArmDownEncoder_H

#include "../CommandBase.h"
#include "WPILib.h"

class AdjustArmDownEncoder: public CommandBase
{
public:
	AdjustArmDownEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
