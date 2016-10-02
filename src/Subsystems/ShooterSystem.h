#ifndef SHOOTERSYSTEM_H
#define SHOOTERSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"


class ShooterSystem : public Subsystem
{

public:
	ShooterSystem();

	void InitDefaultCommand();
	void Display();
	void ResetShooterEncoder();
	void ArmDown();
	void ArmUp();
	bool IsDownAutonomous();
	bool IsUpAutonomous();
	bool IsDown();
	bool IsUp();
	void StopArm();
	void Intake();
	void StopShooter();
	bool IsStopped();
	void Shoot();

private:
	VictorSP shooterL, shooterR;
	Encoder shooterEncoder;

	VictorSP shooterLift;

	double shooterTickGoal; // Tick to degree ratio

};


#endif
