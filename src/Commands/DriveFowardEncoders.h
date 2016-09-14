#ifndef DriveFowardEncoders_H
#define DriveFowardEncoders_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFowardEncoders: public CommandBase
{
public:
	DriveFowardEncoders();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
}

#endif
