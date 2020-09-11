/*
 * @author Anne-Sophie GILLES
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
     * @param time
     * @param simulation
     */
    Arrival(double time, Simulation & simulation);
    /**
     * Arrival Copy-Constructor
     * @param arrival
     */
    Arrival(const Arrival & arrival);
    /**
     * Launch Arrival's process
     */
    void process() override;
};

#endif