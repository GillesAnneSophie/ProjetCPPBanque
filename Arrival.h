/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_ARRIVAL_H
#define PROJECT_ARRIVAL_H

#include "Event.h"
#include "Cashier.h"
#include "Client.h"
#include "Simulation.h"

class Arrival : public Event{
private:
    Cashier * cashier;
    Client * client;
    Simulation * simulation;

public:
    Arrival(double time, Simulation & simulation);
    Arrival(const Arrival & arrival);
    void process();
};

#endif