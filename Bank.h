/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_BANK_H
#define PROJECT_BANK_H

#include "Cashier.h"
#include "Queue.h"

class Bank{
private:
    int cashiersCount;
    int clientsCount;
    Cashier ** cashiers;
    Queue * queue;

public:
    Bank(double averageServiceTime, int cashiersCount);
    int getCashiersCount();
    int getClientsCount();
    Cashier getFirstAvailableCashier();
};

#endif