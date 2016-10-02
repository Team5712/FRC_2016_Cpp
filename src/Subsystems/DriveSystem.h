#ifndef DRIVESYSTEM_H
#define DRIVESYSTEM_H

class driveSystem : Subsystem {

public:

driveSystem();

void display();
void initDefaultCommand();
void resetDriveEncoders();
void resetGyro();
void invertMotorsTrue();
void invertMotorsFalse();
void driveStraightForward();
bool isUnderLowbar();
void stop();
bool isStopped();
void turnXdegrees();
bool isTurned();


};

#undef DRIVESYSTEM_H
