#ifndef DriveFowardEncoders_H
#define DriveFowardEncoders_H

#include "../Command.h"
#include "WPILib.h"

class DriveFowardEncoders: public Command
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
