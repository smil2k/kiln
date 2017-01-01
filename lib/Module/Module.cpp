/*
 * File:   Module.cpp
 * Author: smil
 *
 * Created on February 14, 2012, 6:03 PM
 */

#include "Arduino.h"
#include "Module.h"

struct ModuleLink {
    int startLevel;
    Module *module;

    ModuleLink *next;
};

static ModuleLink *head = NULL;
static ModuleLink *tail = NULL;

Module::Module(int lvl) {
    mylink = new ModuleLink();
    mylink->startLevel = lvl;
    mylink->module = this;

    if (tail) {
        tail->next = mylink;
        tail = mylink;
    } else {
        head = tail = mylink;
    }
}

Module::~Module() {
    // TODO - unlink / delete "mylink"
    mylink->module = NULL;
}

void beginModules() {
    for (int startLevel = 0; startLevel < MAX_STARTLEVEL; startLevel++) {

        ModuleLink *current = head;

        while (current) {
            if (current->module && current->startLevel == startLevel) {
                current->module->Begin();
            }

            current = current->next;
        }
    }
}

void loopModules() {
    ModuleLink *current = head;

    while (current) {
        if (current->module) {
            current->module->Loop();
        }

        current = current->next;
    }
}

