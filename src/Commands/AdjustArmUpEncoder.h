#ifndef AdjustArmDownEncoder_H
#define AdjustArmDownEncoder_H

#include "../CommandBase.h"
#include "WPILib.h"

class AdjustArmUpEncoder: public CommandBase
{
public:
	AdjustArmUpEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
