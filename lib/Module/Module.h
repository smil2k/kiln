/*
 * File:   Module.h
 * Author: smil
 *
 * Created on February 14, 2012, 6:03 PM
 */

#ifndef MODULE_H
#define MODULE_H

/**
 * Number of start levels.
 * 3 means, there will be start levels 0,1,2
 */
#define MAX_STARTLEVEL 3

#define START_SYSTEM 0
#define START_LIBRARY 1
#define START_APPLICATION 2


/**
 * Each module of the program can inherit from this class, thus getting a piece
 * of the life-cycle.
 *
 * Each component can delegate instructions into the main loop / begin.
 *
 * Components can specify a start level for themselves, so the order of 'begin'
 * calls can be customized.
 *
 * The system will first start the level 0 components and then will increase the
 * level until the max start level is reached. If your component start level is
 * above this level, your component will never start!
 *
 * Don't copy modules! They should be static initialized objects.
 *
 * @param startlevel
 */

struct ModuleLink;

class Module {
public:
  Module(int startlevel = START_APPLICATION);
  virtual ~Module();

  virtual void Loop() {};

  virtual void Begin() {};

private:
  ModuleLink *mylink;
};

void loopModules();
void beginModules();

#endif /* MODULE_H */

