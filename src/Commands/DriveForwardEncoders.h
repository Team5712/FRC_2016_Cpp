#ifndef DriveFowardEncoders_H
#define DriveFowardEncoders_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveForwardEncoders: public Command
{
public:
	DriveForwardEncoders();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
private:
	
};

#endif
