#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H

class shooterSubsystem : Subsystem {

ShooterSubsystem();
void initDefaultCommand();
void display();
void resetShooterEncoder();
bool isDownAutonomous();
bool isDown();
void armUp();
bool isUp();
void stopArm();
void intake();
void stopShooter();
bool isStopped();
void shoot();

};

#endif
