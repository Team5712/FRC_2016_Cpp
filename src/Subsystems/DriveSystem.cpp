#ifndef DRIVESUBSYSTEM_cpp
#define DRIVESUBSYSTEM_cpp

#include "DriveSystem.h"
#include "../RobotMap.h"


void DriveSystem::DriveSystem()
{
	
	updateRateHZ = 50;
	driveTickGoal = 2 * -1000;

	leftFront = VictorSP(RobotMap::LEFT_FRONT_MOTOR);
	leftRear = VictorSP(RobotMap::LEFT_REAR_MOTOR);
	rightFront = VictorSP(RobotMap::RIGHT_FRONT_MOTOR);
	rightRear = VictorSP(RobotMap::RIGHT_REAR_MOTOR);
	
	drive = RobotDrive(leftFront, leftRear, rightFront, rightRear);
	
	leftDriveEncoder = Encoder(RobotMap::LEFT_DRIVE_ENCODER_A, RobotMap::LEFT_DRIVE_ENCODER_B, false, Encoder::EncodingType::k4X);
	rightDriveEncoder = Encoder(RobotMap::RIGHT_DRIVE_ENCODER_A, RobotMap::RIGHT_DRIVE_ENCODER_B, false, Encoder::EncodingType::k4X);
	
	gyro = AHRS(SerialPort::Port::kMXP);
}

void DriveSystem::Display()
{
	SmartDashboard::PutNumber("Encoder (Left Drive)", leftDriveEncoder.Get());
	SmartDashboard::PutNumber("Encoder (Right Drive)", rightDriveEncoder.Get());
//	SmartDashboard::PutNumber("Gyro Yaw", gyro.getYaw());
//	SmartDashboard::PutNumber("Gyro X", gyro.getDisplacementX());
//	SmartDashboard::PutNumber("Gyro Y", gyro.getDisplacementY());
}
	
void DriveSystem::InitDefaultCommand()
{

}

void DriveSystem::resetDriveEncoders()
{
	leftDriveEncoder.reset();
	rightDriveEncoder.reset();
}

void DriveSystem::resetGyro()
{
	gyro.reset();
}

void DriveSystem::invertMotorsTrue()
{
	drive.setInvertedMotor(RobotDrive.MotorType.kFrontLeft, true);
	drive.setInvertedMotor(RobotDrive.MotorType.kFrontRight, true);
	drive.setInvertedMotor(RobotDrive.MotorType.kRearLeft, true);
	drive.setInvertedMotor(RobotDrive.MotorType.kRearRight, true);
}

void DriveSystem::invertMotorsFalse()
{
	drive.setInvertedMotor(RobotDrive.MotorType.kFrontLeft, false);
	drive.setInvertedMotor(RobotDrive.MotorType.kFrontRight, false);
	drive.setInvertedMotor(RobotDrive.MotorType.kRearLeft, false);
	drive.setInvertedMotor(RobotDrive.MotorType.kRearRight, false);
}

void DriveSystem::driveStraightForward()
{
	leftFront.set(-0.7);
	leftRear.set(-0.7);
	rightFront.set(0.7);
	rightRear.set(0.7);
	if(gyro.getYaw() > 2)
	{
		rightFront.set(0.8);
		rightRear.set(0.8);
	}
	if(gyro.getYaw() < -2)
	{
		leftFront.set(-0.8);
		leftRear.set(-0.8);
	}
}

bool DriveSystem::isUnderLowbar()
{
	if(leftDriveEncoder.get() > driveTickGoal)
	{
		return true;
	} else
	{
		return false;
	}
}

void DriveSystem::stop()
{
	leftFront.set(0);
	leftRear.set(0);
	rightFront.set(0);
	rightRear.set(0);
}

bool DriveSystem::isStopped()
{
	if((leftFront.get() == 0) && (leftRear.get() == 0)
			&& (rightFront.get() == 0) && (rightRear.get() == 0))
	{
		return true;
	} else
	{
		return false;
	}
}

void DriveSystem::turnXdegrees()
{
	if (gyro.getYaw() > -degreesTurn )
	{
		leftFront.set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
		leftRear.set(0.4 + (-degreesTurn - gyro.getYaw())/180);
		rightFront.set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
		rightRear.set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
	} else if (gyro.getYaw() < (-degreesTurn - 3))
	{
		leftFront.set(0.4 - (-degreesTurn - gyro.getYaw())/180);
		leftRear.set(-0.4 - (-degreesTurn - gyro.getYaw())/180);
		rightFront.set(0.4 - (-degreesTurn - gyro.getYaw())/180);
		rightRear.set(0.4 - (-degreesTurn - gyro.getYaw())/180);
	}
}

bool DriveSystem::isTurnedX()
{
	if((gyro.getYaw() < -degreesTurn) && (gyro.getYaw() > -degreesTurn - 3))
	{
		return true;
	} else{
		return false;
	}
}



