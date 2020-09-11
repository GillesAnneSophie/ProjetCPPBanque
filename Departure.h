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
    /**
     * Departure Constructor
     * @param time
     * @param client
     * @param cashier
     */
    Departure(double time, Client & client, Cashier & cashier);
    /**
     * Departure Copy-Constructor
     * @param departure
     */
    Departure(const Departure & departure);
    /**
     * Launch Departure's process
     */
    void process() override;
};

#endif