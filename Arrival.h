/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_ARRIVAL_H
#define PROJECT_ARRIVAL_H

#include "Event.h"
#include "Cashier.h"
#include "Client.h"

class Arrival : public Event{
private:
    Cashier * cashier;
    Client * client;

public:
    Arrival(double time, Cashier & cashier, Client & client);
    void process();
};

#endif