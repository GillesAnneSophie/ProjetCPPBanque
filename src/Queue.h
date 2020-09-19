/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <iostream>
#include <deque>
#include "Client.h"
#include "Bank.h"

using namespace std;

class Bank;

/**
 * Queue class. Given private attributes are :
 * - clientQueue deque<Client *> - basically a FIFO (First In First out) queue
 * - maxLength Int - the maximum length of the queue reached during the simulation
 * - integral Double - the result of the calculated integral for the average length
 * - bank Bank - an access to the Bank object
 * - waitingTime Double - the average waiting time in the queue
*/
class Queue{
private:
    deque<Client *> clientQueue;
    int maxLength;
    double integral;
    Bank * bank;
    double waitingTime;

public:
    /**
     * Queue Constructor
     * @param bank Bank - reference parameter to access simulation data from bank
     */
    explicit Queue(Bank & bank);
    /**
     * Queue Copy-Constructor
     * @param queue Queue
     */
    Queue(const Queue & queue);
    /**
     * Get max length of the queue reached during the simulation
     * @return maxLength Int
     */
    int getMaxLength();
    /**
     * Get average length of the queue
     * @return averageLength Double
     */
    double getAverageLength();
    /**
     * Get average waiting time in the queue
     * @return averageWaitingTime Double
     */
    double getAverageWaitingTime();
    /**
     * Add client to clientQueue
     * @param client Client
     */
    void addClient(Client & client);
    /**
     * Get clientQueue emptiness
     * @return Boolean - according to queue emptiness
     */
    bool isEmpty();
    /**
     * Remove first client from clientQueue and return it
     * @return Client
     */
    Client * remove();
};

#endif