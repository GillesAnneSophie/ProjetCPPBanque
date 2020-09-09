/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_DEPARTURE_H
#define PROJECT_DEPARTURE_H

#include "Event.h"

class Departure : public Event{
private:

public:
    Departure(double time);
    void process();
};

#endif