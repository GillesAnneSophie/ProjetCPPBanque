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


class Queue{
private:
    deque<Client> clientQueue;
    int maxLength;
    double integral; //TODO calcul de l'intégrale
    Bank * bank;

public:
    Queue(Bank * bank);
    int getMaxLength();
    double getAverageLength();
    double getAverageWaitingTime();
    void addClient(Client client);
    bool isEmpty();
    Client remove();
};

#endif