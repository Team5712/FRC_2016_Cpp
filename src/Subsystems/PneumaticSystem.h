#ifndef PNEUMATICSYSTEM_H
#define PNEUMATICSYSTEM_H

class PneumaticSystem : Subsystem {

  public:
  
  void PneumaticSubsystem();
  void initDefaultCommand();
  void shiftHigh();
  void shiftLow();
  void in();
  void out();
  
};

#endif
