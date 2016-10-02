#include "AutonomousPlanner.h"


AutonomousPlanner::AutonomousPlanner(string defense, int position)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(Robot::driveSystem);

	// "Save" these values for later use
	this->defense = defense;
	this->position = position;
	hasLoaded = false;
}

// Called just before this Command runs the first time
void AutonomousPlanner::Initialize()
{
	// Populate the maps
	InitInformation();
}

// Called repeatedly when this Command is scheduled to run
void AutonomousPlanner::Execute()
{
	// Set driveSubsystem's values
	LoadDriveInfo(defense, position);

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

// Fills the maps (encoderInfo, angleInfo, speedInfo) with
// pre-programmed data. encoderInfo & angleInfo look at the
// position of the robot, whereas speedInfo looks at the
// defense the robot will be crossing
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

// Sets the driveSubsytem's values (gotten from the maps)
// based on the defense and the position of the robot. These
// variables are determined by the SmartDasboard
void AutonomousPlanner::LoadDriveInfo(string def, int pos)
{

	// Variables for easy readability; not needed
	int newDriveTickGoal = 0;
	double newAngle = 0.0;
	double newSpeed = 0.0;

	// second stands for the second value in the map
	newDriveTickGoal = encoderInfo.find(pos)->second;
	newAngle = angleInfo.find(pos)->second;

	// If there is a value for the defense, set it
	if(speedInfo.find(def) != speedInfo.end())
	{
		newSpeed = speedInfo.find(def)->second;
	} else
	{ // Otherwise, set it to a default value
		newSpeed = speedInfo.find("default")->second;
	}

	// Update the drive subsystem's values
	Robot::driveSystem->SetDriveTickGoal(newDriveTickGoal);
	Robot::driveSystem->SetDegreesTurn(newAngle);
	Robot::driveSystem->SetSpeed(newSpeed);

	hasLoaded = true;
}


