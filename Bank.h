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
    /**
     * Bank Constructor
     * @param averageServiceTime
     * @param cashiersCount
     * @param simulation
     */
    Bank(double averageServiceTime, int cashiersCount, Simulation & simulation);
    /**
     * Bank Copy-Constructor
     * @param bank
     */
    Bank(const Bank & bank)
    /**
     * Bank Destructor
     */
    ~Bank();
    /**
     * Get clients count
     * @return clientsCount
     */
    int getClientsCount();
    /**
     * Add a client to clientsCount
     */
    void addClientToCount();
    /**
     * Get the first (from 0 to cashiersCount) available cashier
     * @return cashier|null
     */
    Cashier* getFirstAvailableCashier();
    /**
     * Get queue
     * @return queue
     */
    Queue & getQueue();
    /**
     * Get simulation
     * @return simulation
     */
    Simulation & getSimulation();
    /**
     * Get the cashier at given place in cashiers
     * @param index
     * @return cashier
     */
    Cashier& getCashier(int index);
};

#endif