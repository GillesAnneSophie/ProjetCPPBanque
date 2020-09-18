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
     * @param averageServiceTimes Average Service times for each cashier during the simulation
     * @param cashiersCount Number of Cashiers-class objects during the simulation 
     * @param simulation Simulation reference parameter to access simulation data from bank
     */
    Bank(double * averageServiceTimes, int cashiersCount, Simulation & simulation);
    /**
     * Bank Copy-Constructor
     * @param bank Bank reference parameter
     */
    Bank(const Bank & bank);
    /**
     * Bank Destructor
     */
    ~Bank();
    /**
     * Get clients count
     * @return clientsCount Integer return value
     */
    int getClientsCount();
    /**
     * Add a client to clientsCount
     */
    void addClientToCount();
    /**
     * Get the first (from 0 to cashiersCount) available cashier
     * @return A cashier object if available or null
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