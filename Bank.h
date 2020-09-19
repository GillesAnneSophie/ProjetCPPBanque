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
 *  Bank class. Some private attributes are given to represent a real life bank such as :
 * - The number of cashiers
 * - The total number of clients that came in the bank
 * - An array of cashiers existing in the bank
 * - A queue for the customers / clients
 * - An access to the Simulation object
 */
class Bank{
private:
    int cashiersCount; /**< Number of Cashiers during in the bank (during the simulation) */
    int clientsCount; /**< Total number of clients that came in the bank*/
    Cashier ** cashiers; /**< Pointer on an array of Cashier objects, the Cashiers in the bank */
    Queue * queue; /**< Pointer on a Queue object, representing the Clients' queue */
    Simulation * simulation; /**< Pointer on the Simulation object for easy access */

public:
    /**
     * Bank Constructor
     * @param averageServiceTimes Average Service times for each cashier during the Simulation
     * @param cashiersCount Number of Cashier class objects during the simulation 
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
     * @return clientsCount as an Integer return value
     */
    int getClientsCount();
    /**
     * Add a client to the clientsCount attribute by increment
     */
    void addClientToCount();
    /**
     * Get the first (from 0 to cashiersCount) available cashier
     * @return A cashier object if available or null
     */
    Cashier* getFirstAvailableCashier();
    /**
     * Get Queue attribute
     * @return queue as a reference Queue return value
     */
    Queue & getQueue();
    /**
     * Get Simulation attribute
     * @return simulation as a reference Simulation return value
     */
    Simulation & getSimulation();
    /**
     * Get the cashier at given index in cashiers attribute
     * @param index
     * @return cashier
     */
    Cashier& getCashier(int index);
};

#endif