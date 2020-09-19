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
 * Queue class representing the queue of customers in the bank. Given private attributes are :
 * - clientQueue : deque<Client *> attribute, which is behaving as a FIFO (First In First out).
 * - maxLength : integer attribute, where the maximum length of the queue reached during the simulation is saved. 
 * - integral : double attribute where the result of the calculated integral is kept, used when calculating queue average length.
 * - bank : Bank-Pointer attribute, for easy access to the bank instance.
 * - waitingTime : double attribute, used when calculating average serving time.
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
     * @param bank Reference in which the queue is part of
     */
    explicit Queue(Bank & bank);
    /**
     * Queue Copy-Constructor
     * @param queue
     */
    Queue(const Queue & queue);
    /**
     * Get max length of the queue reached during the simulation.
     * @return maxLength as an integer value
     */
    int getMaxLength();
    /**
     * Get average length of the queue during the simulation.
     * @return averageLength as a double value
     */
    double getAverageLength();
    /**
     * Get average waiting time during the simulation.
     * @return averageWaitingTime as a double value.
     */
    double getAverageWaitingTime();
    /**
     * Add client to clientQueue
     * @param client to be added in the queue.
     */
    void addClient(Client & client);
    /**
     * Get if clientQueue is empty
     * @return 
     * - true if clientQueue is empty
     * - Else return false
     */
    bool isEmpty();
    /**
     * Remove first client from clientQueue and returns it
     * @return Client
     */
    Client * remove();
};

#endif