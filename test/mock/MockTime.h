/*
 * All rights reserved.
 */

/*
 * File:   Time.h
 * Author: smil
 *
 * Created on February 12, 2017, 3:31 PM
 */

#ifndef TIME_H
#define TIME_H

#include "Module.h"

class Time : private Module {
public:
  Time();

  void SetIncrements( long increments );

  virtual void Begin();
  virtual void Loop();

private:
  long increments;
  long time;
};

extern Time time;

#endif /* TIME_H */

