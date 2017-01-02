/*
 * All rights reserved.
 */

/*
 * File:   Heatelement.h
 * Author: smil
 *
 * Created on January 2, 2017, 2:51 PM
 */

#ifndef HEATELEMENT_H
#define HEATELEMENT_H

#include <Module.h>
#include <Metro.h>

class Heatelement : public Module {
public:
  Heatelement(int pin);

  void ManualControl(uint8_t duty);
  void AutoControl(double target);

  virtual void Loop();
  void KeepDuty();


  uint8_t Duty() {
    return duty;
  }
  double Target() {
    return target;
  }
private:

  void SetDuty(uint8_t duty);

  int pin;

  double target;
  bool targetLock;

  uint8_t duty;

  uint8_t heatedSlots;
  uint8_t totalSlots;

  Metro heatCheck;
  Metro autoCheck;
};

#endif /* HEATELEMENT_H */

