#ifndef DriveAutonomous_H
#define DriveAutonomous_H

#include "iostream"
#include "string"
#include "algorithm"

#include "Commands/CommandGroup.h"
#include "WPILib.h"


using namespace std;

class DriveAutonomous: public CommandGroup
{

public:
	DriveAutonomous(string, int, bool);

private:
	bool InsensitiveCompare(string, string);

};

#endif
