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
     * @param bank
     */
    Queue(Bank & bank);
    /**
     * Queue Copy-Constructor
     * @param queue
     */
    Queue(const Queue & queue);
    /**
     * Get max length
     * @return maxLength
     */
    int getMaxLength();
    /**
     * Get average length
     * @return averageLength
     */
    double getAverageLength();
    /**
     * Get average waiting time
     * @return averageWaitingTime
     */
    double getAverageWaitingTime();
    /**
     * Add client to clientQueue
     * @param client
     */
    void addClient(Client & client);
    /**
     * Get is clientQueue empty
     * @return true|false
     */
    bool isEmpty();
    /**
     * Remove first client from clientQueue and returns it
     * @return Client
     */
    Client * remove();
};

#endif