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
    deque<Client> clientQueue;
    int maxLength;
    double integral;
    Bank * bank;
    double waitingTime;

public:
    Queue(Bank & bank);
    Queue(const Queue & queue);
    int getMaxLength();
    double getAverageLength();
    double getAverageWaitingTime();
    void addClient(Client & client);
    bool isEmpty();
    Client remove();
};

#endif