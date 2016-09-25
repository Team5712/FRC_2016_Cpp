#ifndef PNEUMATICSYSTEM_H
#define PNEUMATICSYSTEM_H

class PneumaticSystem : Subsystem {

  public:
  
  PneumaticSubsystem();
  initDefaultCommand();
  shiftHigh();
  shiftLow();
  in();
  out();
  
};

#endif
