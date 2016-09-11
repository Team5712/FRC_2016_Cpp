#include "DriveAutonomous.h"

DriveAutonomous::DriveAutonomous(string defense, int position, bool shouldShoot)
{

	AddSequential(new AutonomousPlanner(defense, position));

	if(InsensitiveCompare(defense, "low_bar"))
	{
		AddSequential(new LowerArmAutonomous());
	}
	AddSequential(new DriveForwardEncoders());
	AddSequential(new TurnXDegrees());
	if(shouldShoot)
	{
		AddSequential(new Shoot());
	}

}

// Compares the two strings, NON-case sensitive
bool DriveAutonomous::InsenitiveCompare(string str1, string str2)
{
	// Convert both strings to lowercase
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	if(str1.compare(str2) == 0)
	{
		return true;
	} else {
		return false;
	}

}

// Pro-tips
// e.g. AddSequential(new Command1());
//      AddSequential(new Command2());
// these will run in order.

// To run multiple commands at the same time,
// use AddParallel()
// e.g. AddParallel(new Command1());
//      AddSequential(new Command2());
// Command1 and Command2 will run in parallel.

// A command group will require all of the subsystems that each member
// would require.
// e.g. if Command1 requires chassis, and Command2 requires arm,
// a CommandGroup containing them would require both the chassis and the
// arm.
