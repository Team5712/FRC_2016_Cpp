#ifndef CommandBase_H
#define CommandBase_H

//Incluse all command header files here I think...
#include "OI.h"

class CommandBase : public Comand
{
public:
	CommandBase(const char *name); //Don't know what this does I just copied it form somewhere
	CommandBase(); //This doesn't make sense either but whatever
	
	static void init();
	static DriveSystem *driveSystem;
	static ShooterSystem *shooterSystem;
	static PneumaticSystem *pneumaticSystem;
	static OI *oi;
}

#endif
