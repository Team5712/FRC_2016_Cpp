#ifndef DriveFowardEncoders_H
#define DriveFowardEncoders_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

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
	
};

#endif
