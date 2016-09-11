#include "AutonomousPlanner.h"

using namespace std;

AutonomousPlanner::AutonomousPlanner(string defense, int position)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(exampleSubsystem);

	this->defense = defense;
	this->position = position;

}

// Called just before this Command runs the first time
void AutonomousPlanner::Initialize()
{
	initInformation();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousPlanner::Execute()
{

	loadDriveInfo(defense, position);

}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousPlanner::IsFinished()
{
	return hasLoaded;
}

// Called once after isFinished returns true
void AutonomousPlanner::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousPlanner::Interrupted()
{

}

void AutonomousPlanner::InitInformation()
{

	// Encoder
	// 17 is the ticks / inch ratio
	encoderInfo.insert(pair<int, int>(1, 198 * -17));
	encoderInfo.insert(pair<int, int>(2, 233 * -17));
	encoderInfo.insert(pair<int, int>(3, 144 * -17));
	encoderInfo.insert(pair<int, int>(4, 144 * -17));
	encoderInfo.insert(pair<int, int>(5, 238 * -17));

	// Angle
	angleInfo.insert(pair<int, double>(1, 60.0));
	angleInfo.insert(pair<int, double>(2, 60.0));
	angleInfo.insert(pair<int, double>(3, 15.0));
	angleInfo.insert(pair<int, double>(4, 6.5));
	angleInfo.insert(pair<int, double>(5, 60.0));

	// Speed
	speedInfo.insert(pair<string, double>("default", 0.7));

}

void AutonomousPlanner::LoadDriveInfo(string def, int pos)
{

}
