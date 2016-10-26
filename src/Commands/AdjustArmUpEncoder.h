#ifndef AdjustArmDownEncoder_H
#define AdjustArmDownEncoder_H

#include "WPILib.h"

class AdjustArmUpEncoder: public Command
{
public:
	AdjustArmUpEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif
