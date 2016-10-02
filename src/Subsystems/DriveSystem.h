#ifndef DRIVESYSTEM_H
#define DRIVESYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"


class DriveSystem : public Subsystem
{

public:
	DriveSystem();

	void Display();
	void InitDefaultCommand();
	void ResetDriveEncoders();
	void ResetGyro();
	void InvertMotorsTrue();
	void InvertMotorsFalse();
	void DriveStraightForward();
	bool IsUnderLowbar();
	void Stop();
	bool IsStopped();
	void TurnXdegrees();
	bool IsTurned();

private:


};

#endif DRIVESYSTEM_H
