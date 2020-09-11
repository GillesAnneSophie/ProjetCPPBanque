/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_BANK_H
#define PROJECT_BANK_H

#include "Cashier.h"
#include "Queue.h"
#include "Simulation.h"

class Cashier;
class Queue;
class Simulation;

class Bank{
private:
    int cashiersCount;
    int clientsCount;
    Cashier ** cashiers;
    Queue * queue;
    Simulation * simulation;

public:
    Bank(double averageServiceTime, int cashiersCount, Simulation * simulation);
    Bank(const Bank & bank);
    ~Bank();
    int getCashiersCount();
    int getClientsCount();
    Cashier* getFirstAvailableCashier();
    Queue & getQueue();
    Simulation & getSimulation();
};

#endif