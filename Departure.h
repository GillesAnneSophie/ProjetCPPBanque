/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_DEPARTURE_H
#define PROJECT_DEPARTURE_H

#include "Event.h"
#include "Simulation.h"

class Cashier;

/**
 * Departure class, inheriting from Event class. Representing the departure of a client from the bank. Given private attributes are :
 *- cashier : A Cashier-pointer attribute, indicating the cashier that finished serving the client.
 *- client : A Client-pointer attribute, indicating the client that is going to depart from the bank.
 */
class Departure : public Event{
private:
    Client * client;
    Cashier * cashier;
    
public:
    /**
     * Departure Constructor.
     * @param time Departure time
     * @param client Departing client
     * @param cashier Cashier that served the client and which is going to be available
     */
    Departure(double time, Client & client, Cashier & cashier);
    /**
     * Departure Copy-Constructor.
     * @param departure
     */
    Departure(const Departure & departure);
    /**
     * Launch Departure's process. The cashier associated with the departure is going to be enabled, while the client while by destroyed.
     */
    void process() override;
};

#endif