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

/**
 *  Bank class. Given private attributes are :
 * - cashiersCount Int - the number of cashiers
 * - clientsCount Int - the total number of clients who came in the bank
 * - cashiers Cashier[] - an array of cashiers existing in the bank
 * - queue Queue - the clients' queue
 * - simulation Simulation - an access to the Simulation object
 */
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
     * @param averageServiceTimes Double - average Service time for each cashier during the Simulation
     * @param cashiersCount Int - number of Cashier class objects during the simulation
     * @param simulation Simulation - reference parameter to access simulation data from bank
     */
    Bank(double * averageServiceTimes, int cashiersCount, Simulation & simulation);
    /**
     * Bank Copy-Constructor
     * @param bank Bank
     */
    Bank(const Bank & bank);
    /**
     * Bank Destructor
     */
    ~Bank();
    /**
     * Get clients count
     * @return clientsCount Int
     */
    int getClientsCount();
    /**
     * Add a client to the clientsCount attribute by increment
     */
    void addClientToCount();
    /**
     * Get the first (from 0 to cashiersCount) available cashier
     * @return Cashier|nullptr
     */
    Cashier* getFirstAvailableCashier();
    /**
     * Get Queue attribute
     * @return Queue
     */
    Queue & getQueue();
    /**
     * Get Simulation attribute
     * @return Simulation
     */
    Simulation & getSimulation();
    /**
     * Get the cashier at given index in cashiers attribute
     * @param index Int
     * @return Cashier
     */
    Cashier& getCashier(int index);
};

#endif