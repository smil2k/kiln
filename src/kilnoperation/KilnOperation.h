/*
 * All rights reserved.
 */

/*
 * File:   KilnOperation.h
 * Author: smil
 *
 * Created on February 11, 2017, 8:26 PM
 */

#ifndef KILNOPERATION_H
#define KILNOPERATION_H

#define PARAM_NONE 0
#define PARAM_TEMP 1
#define PARAM_TIME 2

#include "../common.h"

class KilnOperation {
public:
  KilnOperation(const char* name, uint8_t param) :
    name(name), param(param) {
  }

  // return true -> finished
  virtual bool Loop();

  KilnOperation *next;
private:
  const char *name;
  uint8_t param;
};

KilnOperation *GetKilnOperationList();

#endif /* KILNOPERATION_H */

