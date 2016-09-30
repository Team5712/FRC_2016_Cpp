#ifndef DRIVESYSTEM_cpp
#define DRIVESYSTEM_cpp
#include <RobotMap.h>
#include <RobotMap.cpp>
#include <AHRS.h>
#include <AHRS.cpp>
#include <Encoder.h>
#include <Encoder.cpp>
#include <RobotDrive.h>
#include <RobotDrive.cpp>
#include <SerialPort.h>
#include <SerialPort.cpp>
#include <VictorSP.h>
#include <VictorSP.cpp>
#include <Subystem.h>
#include <Subsystem.cpp>
#include <SmartDashboard.h>
#include <SmartDashboard.cpp>

/**
 *
 */
class Drivesystem : public Subsystem {
	
	private:
	
	VictorSP leftFront, leftRear, rightFront, rightRear;
	
	public:
	
	RobotDrive drive;
	
	Encoder leftDriveEncoder, rightDriveEncoder;
	
	AHRS gyro;
	SerialPort serial_port;
		
	int update_rate_hz = 50;
	double degreesTurn;
	
	int driveTickGoal = 2 * -1000;
	
	void Drivesystem::Drivesystem(){
		
		leftFront = VictorSP(RobotMap.LEFT_FRONT_MOTOR);
		leftRear = VictorSP(RobotMap.LEFT_REAR_MOTOR);
		rightFront = VictorSP(RobotMap.RIGHT_FRONT_MOTOR);
		rightRear = VictorSP(RobotMap.RIGHT_REAR_MOTOR);
		
		drive = RobotDrive(leftFront, leftRear, rightFront, rightRear);
		
		leftDriveEncoder = Encoder(RobotMap.LEFT_DRIVE_ENCODER_A, RobotMap.LEFT_DRIVE_ENCODER_B, false, Encoder.EncodingType.k4X);
		rightDriveEncoder = Encoder(RobotMap.RIGHT_DRIVE_ENCODER_A, RobotMap.RIGHT_DRIVE_ENCODER_B, false, Encoder.EncodingType.k4X);
	
		gyro = AHRS(SerialPort.Port.kMXP);
	}
	
	void display(){
		SmartDashboard.putNumber("Encoder (Left Drive)", leftDriveEncoder.get());
		SmartDashboard.putNumber("Encoder (Right Drive)", rightDriveEncoder.get());
		SmartDashboard.putNumber("Gyro Yaw", gyro.getYaw());
		SmartDashboard.putNumber("Gyro X", gyro.getDisplacementX());
		SmartDashboard.putNumber("Gyro Y", gyro.getDisplacementY());
	}
	
	void initDefaultCommand() {
	}
	
	void resetDriveEncoders(){
		leftDriveEncoder.reset();
		rightDriveEncoder.reset();
	}
	
	void resetGyro(){
		gyro.reset();
	}
    
    void invertMotorsTrue(){
    	drive.setInvertedMotor(RobotDrive.MotorType.kFrontLeft, true);
    	drive.setInvertedMotor(RobotDrive.MotorType.kFrontRight, true);
    	drive.setInvertedMotor(RobotDrive.MotorType.kRearLeft, true);
    	drive.setInvertedMotor(RobotDrive.MotorType.kRearRight, true);
    }
    
    void invertMotorsFalse(){
    	drive.setInvertedMotor(RobotDrive.MotorType.kFrontLeft, false);
    	drive.setInvertedMotor(RobotDrive.MotorType.kFrontRight, false);
    	drive.setInvertedMotor(RobotDrive.MotorType.kRearLeft, false);
    	drive.setInvertedMotor(RobotDrive.MotorType.kRearRight, false);
    }
    
    void driveStraightForward(){
    	leftFront.set(-0.7);
    	leftRear.set(-0.7);
    	rightFront.set(0.7);
    	rightRear.set(0.7);
    	if(gyro.getYaw() > 2){
    		rightFront.set(0.8);
    		rightRear.set(0.8);
    	}
    	if(gyro.getYaw() < -2){
    		leftFront.set(-0.8);
    		leftRear.set(-0.8);
    	}
    }
    
    bool isUnderLowbar(){
    	if(leftDriveEncoder.get() > driveTickGoal){
    		return true;
    	}
    	else{
    		return false;
    	}
    }
    
    void stop(){
    	leftFront.set(0);
    	leftRear.set(0);
    	rightFront.set(0);
    	rightRear.set(0);
    }   
    
    bool isStopped(){
    	if((leftFront.get() == 0) && (leftRear.get() == 0) 
    		&& (rightFront.get() == 0) && (rightRear.get() == 0)){
    		return true;
    	}
    	else{
    		return false;
    	}
    }
    
    void turnXdegrees(){
    	if (gyro.getYaw() > -degreesTurn ) {
    		leftFront.set(-0.4 + (-degreesTurn - gyro.getYaw())/180); 
			leftRear.set(0.4 + (-degreesTurn - gyro.getYaw())/180);
			rightFront.set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
			rightRear.set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
		}
    	else if (gyro.getYaw() < (-degreesTurn - 3)){
    		leftFront.set(0.4 - (-degreesTurn - gyro.getYaw())/180); 
			leftRear.set(-0.4 - (-degreesTurn - gyro.getYaw())/180);
			rightFront.set(0.4 - (-degreesTurn - gyro.getYaw())/180);
			rightRear.set(0.4 - (-degreesTurn - gyro.getYaw())/180);
    	}
    }
    
    bool isTurnedX(){
    	if((gyro.getYaw() < -degreesTurn) && (gyro.getYaw() > -degreesTurn - 3)){
    		return true;
    	}
    	else{
    		return false;
    	}
    }
}
