#include <iostream>

class Robot : public IteritaveRobot
{
  private:
  class RobotDrive *drive;
  class Victor *frontLeft, *frontRight, *rearLeft, *rearRight;
  class Joystick *left, *right;
  
  void AutonomousInit()
  {
    
  }
  
  void AutonomousPeriodic()
  {
    
  }
  
  void TeleopInit()
  {
    frontLeft = new Victor(1);
    frontRight = new Victor(2);
    rearLeft = new Victor(3);
    rearRight = new Victor(4);
    drive = new RobotDrive(frontLeft, frontRight, rearLeft, rearRight);
    left = new Joystick(1);
    right = new Joystick(2);
  }
  
  void operatorControl()
  {
    while(IsOperatorControl() && IsEnabled())
    {
      drive->TankDrive(left, right);
      wait(0.01);
    }
  }
}
