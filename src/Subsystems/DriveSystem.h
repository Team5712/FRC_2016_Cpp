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
	void InvertMotors(bool);
	void DriveStraightForward();
	bool IsUnderLowbar();
	void Stop();
	bool IsStopped();
	void TurnXdegrees();
	bool IsTurnedX();

	// Get / Set
	void SetDriveTickGoal(int);
	int GetDriveTickGoal();
	void SetDegreesTurn(double);
	double GetDegreesTurn();
	void SetSpeed(double);
	double GetSpeed();

private:
	VictorSP leftFront, leftRear, rightFront, rightRear;
	RobotDrive drive;
	Encoder leftDriveEncoder, rightDriveEncoder;

	AHRS gyro;
	SerialPort serialPort;
	const int updateRateHZ;

	int driveTickGoal;
	double degreesTurn;
	double speed;

};

#endif DRIVESYSTEM_H
