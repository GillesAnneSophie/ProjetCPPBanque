/*
 * @author Anne-Sophie GILLES
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_ARRIVAL_H
#define PROJECT_ARRIVAL_H

#include "Event.h"
#include "Cashier.h"
#include "Client.h"
#include "Simulation.h"
#include "Poisson.h"

class Simulation;
class Cashier;

/**
 *  Arrival class, inheriting from Event class. Given private attributes are :
 * - cashier Cashier - the cashier related to the Arrival event
 * - client Client - the client who has just arrived in the bank
 * - simulation Simulation - an access to the Simulation object
 */
class Arrival : public Event{
private:
    Cashier * cashier;
    Client * client;
    Simulation * simulation;

public:
    /**
     * Arrival Constructor
     * @param time Double - the arrival time of the client
     * @param simulation Simulation - reference parameter to access simulation data from bank
     */
    Arrival(double time, Simulation & simulation);
    /**
     * Arrival Copy-Constructor
     * @param arrival Arrival
     */
    Arrival(const Arrival & arrival);
    /**
     * Launch Arrival's process. A new client is created. If a or several Cashier are available, the newly created client is attributed to the first available Cashier. Else, the client goes in the Queue. A new Arrival event is created during the process.
     */
    void process() override;
};

#endif