#include "PneumaticSystem.h"
#include "../RobotMap.h"


class PneumaticSubsystem  Subsystem {

    public:

	DoubleSolenoid shifterSolenoid, shooterSolenoid;

	Compressor compressor;

	public PneumaticSubsystem(){

		shifterSolenoid = new DoubleSolenoid(RobotMap.SHIFTER_SOLENOID_A, RobotMap.SHIFTER_SOLENOID_B);

		shooterSolenoid = new DoubleSolenoid(RobotMap.SHOOTER_SOLENOID_A, RobotMap.SHOOTER_SOLENOID_B);

		compressor = new Compressor(RobotMap.COMPRESSOR);
	}

    void initDefaultCommand() {
    }

    void shiftHigh(){
    	shifterSolenoid.set(DoubleSolenoid.Value.kForward);
    }

    void shiftLow(){
    	shifterSolenoid.set(DoubleSolenoid.Value.kReverse);
    }

    void in(){
    	shooterSolenoid.set(DoubleSolenoid.Value.kReverse);
    }

    void out(){
    	shooterSolenoid.set(DoubleSolenoid.Value.kForward);
    }
}
