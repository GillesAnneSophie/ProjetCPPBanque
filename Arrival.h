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

class Arrival : public Event{
private:
    Cashier * cashier;
    Client * client;
    Simulation * simulation;

public:
    /**
     * Arrival Constructor
     * @param time Double parameter representing the Arrival time (of a client)
     * @param simulation Simulation-class reference parameter to keep track of the current Simulation object
     */
    Arrival(double time, Simulation & simulation);
    /**
     * Arrival Copy-Constructor
     * @param arrival Arrival-class reference parameter
     */
    Arrival(const Arrival & arrival);
    /**
     * Launch Arrival's process. A new client is created. If a Cashier is available, the newly created client is attributed. Else, the client goes in the queue. A new Arrival Event is created during the process.
     */
    void process() override;
};

#endif