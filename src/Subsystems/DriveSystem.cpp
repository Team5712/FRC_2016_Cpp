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

//	gyro = AHRS(SerialPort::Port::kMXP);
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

//void DriveSystem::ResetDriveEncoders()
//{
//	leftDriveEncoder.reset();
//	rightDriveEncoder.reset();
//}
//
//void DriveSystem::ResetGyro()
//{
//	gyro.reset();
//}

void DriveSystem::InvertMotors(bool invert)
{
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, invert);
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor, invert);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, invert);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor, invert);
}

//void DriveSystem::DriveStraightForward()
//{
//	leftFront.Set(-0.7);
//	leftRear.Set(-0.7);
//	rightFront.Set(0.7);
//	rightRear.Set(0.7);
//	if(gyro.getYaw() > 2)
//	{
//		rightFront.Set(0.8);
//		rightRear.Set(0.8);
//	}
//	if(gyro.getYaw() < -2)
//	{
//		leftFront.Set(-0.8);
//		leftRear.Set(-0.8);
//	}
//}

bool DriveSystem::IsUnderLowbar()
{
	if(leftDriveEncoder.Get() > driveTickGoal)
	{
		return true;
	} else
	{
		return false;
	}
}

void DriveSystem::Stop()
{
	leftFront.Set(0);
	leftRear.Set(0);
	rightFront.Set(0);
	rightRear.Set(0);
}

bool DriveSystem::IsStopped()
{
	if((leftFront.Get() == 0) && (leftRear.Get() == 0)
			&& (rightFront.Get() == 0) && (rightRear.Get() == 0))
	{
		return true;
	} else
	{
		return false;
	}
}

//void DriveSystem::TurnXdegrees()
//{
//	if (gyro.getYaw() > -degreesTurn )
//	{
//		leftFront.Set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
//		leftRear.Set(0.4 + (-degreesTurn - gyro.getYaw())/180);
//		rightFront.Set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
//		rightRear.Set(-0.4 + (-degreesTurn - gyro.getYaw())/180);
//	} else if (gyro.getYaw() < (-degreesTurn - 3))
//	{
//		leftFront.Set(0.4 - (-degreesTurn - gyro.getYaw())/180);
//		leftRear.Set(-0.4 - (-degreesTurn - gyro.getYaw())/180);
//		rightFront.Set(0.4 - (-degreesTurn - gyro.getYaw())/180);
//		rightRear.Set(0.4 - (-degreesTurn - gyro.getYaw())/180);
//	}
//}
//
//bool DriveSystem::IsTurnedX()
//{
//	if((gyro.getYaw() < -degreesTurn) && (gyro.getYaw() > -degreesTurn - 3))
//	{
//		return true;
//	} else{
//		return false;
//	}
//}

// Get / Set methods

void DriveSystem::SetDriveTickGoal(int newTickGoal)
{
	driveTickGoal = newTickGoal;
}
int DriveSystem::GetDriveTickGoal()
{
	return driveTickGoal;
}

void DriveSystem::SetDegreesTurn(double newDegrees)
{
	degreesTurn = newDegrees;
}
double DriveSystem::GetDegreesTurn()
{
	return degreesTurn;
}

void DriveSystem::SetSpeed(double newSpeed)
{
	speed = newSpeed;
}
double DriveSystem::GetSpeed()
{
	return speed;
}


