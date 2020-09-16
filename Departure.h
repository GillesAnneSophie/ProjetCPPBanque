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
    double serviceTime;
    
public:
    /**
     * Departure Constructor
     * @param time
     * @param client
     * @param cashier
     * @param serviceTime
     */
    Departure(double time, Client & client, Cashier & cashier, double serviceTime);
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