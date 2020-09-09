/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_COMPAREEVENTPRIORITY_H
#define PROJECT_COMPAREEVENTPRIORITY_H

#include "Event.h"

class CompareEventPriority{
public:
    int operator() (Event * & e1, Event * & e2);
};

#endif