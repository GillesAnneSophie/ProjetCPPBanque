/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_DEPARTURE_H
#define PROJET_DEPARTURE_H

#include "Event.h"

class Departure : public Event{
private:

public:
    Departure(double time);
    void process();
};

#endif