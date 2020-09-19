/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_DEPARTURE_H
#define PROJECT_DEPARTURE_H

#include "Event.h"
#include "Simulation.h"

class Cashier;

/**
 * Departure class, inheriting from Event class. Given private attributes are :
 * - cashier Cashier - the cashier related to the Departure event
 * - client Client - the client who has just arrived in the bank
 */
class Departure : public Event{
private:
    Client * client;
    Cashier * cashier;
    
public:
    /**
     * Departure Constructor
     * @param time Double - the arrival time of the client
     * @param client Client - the client who is leaving the bank
     * @param cashier Cashier - the cashier who served the client
     */
    Departure(double time, Client & client, Cashier & cashier);
    /**
     * Departure Copy-Constructor
     * @param departure Departure
     */
    Departure(const Departure & departure);
    /**
     * Launch Departure's process. The cashier associated with the departure is going to be available, while the client will be destroyed.
     */
    void process() override;
};

#endif