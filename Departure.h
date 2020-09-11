/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_DEPARTURE_H
#define PROJECT_DEPARTURE_H

#include "Event.h"
#include "Simulation.h"

class Cashier;

class Departure : public Event{
private:
    Client * client;
    Cashier * cashier;

public:
    Departure(double time, Client & client, Cashier & cashier);
    Departure(const Departure & departure);
    void process() override;
};

#endif