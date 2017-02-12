/*
 * All rights reserved.
 */

/*
 * File:   Time.cpp
 * Author: smil
 *
 * Created on February 12, 2017, 3:31 PM
 */

#include "MockTime.h"

Time::Time() {

}

void Time::Begin() {
  this->time = 0;
}

void Time::Loop() {
  this->time += increments;
}

void Time::SetIncrements(long increments) {
  this->increments = increments;
}



