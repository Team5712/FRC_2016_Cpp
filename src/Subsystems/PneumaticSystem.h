#ifndef PNEUMATICSYSTEM_H
#define PNEUMATICSYSTEM_H


class PneumaticSystem : public Subsystem
{

public:

	PneumaticSystem();

	void InitDefaultCommand();
	void ShiftHigh();
	void ShiftLow();
	void In();
	void Out();

private:

	DoubleSolenoid shifterSolenoid, shooterSolenoid;
	Compressor compressor;

};


#endif
