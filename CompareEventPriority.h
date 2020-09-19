/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_COMPARE_EVENT_PRIORITY_H
#define PROJECT_COMPARE_EVENT_PRIORITY_H

#include "Event.h"

class CompareEventPriority{
public:
    /**
     * Compare events priority
     * @param e1 Event
     * @param e2 Event
     * @return Int - 0 or 1
     */
    int operator() (Event * & e1, Event * & e2);
};

#endif