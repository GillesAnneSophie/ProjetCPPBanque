/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_DEPARTURE_H
#define PROJECT_DEPARTURE_H

#include "Event.h"
#include "Simulation.h"

class Departure : public Event{
private:
    Simulation * simulation;
    Client * client;

public:
    Departure(double time, Client & client, Simulation & simulation);
    void process();
};

#endif