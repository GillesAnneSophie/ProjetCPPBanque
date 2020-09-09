/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_BANK_H
#define PROJET_BANK_H

#include "Cashier.h"

class Bank{
private:
    int cashiersCount;
    int clientsCount;

public:
    Bank(double averageServiceTime, int cashiersCount);
    int getCashiersCount();
    int getClientsCount();
    Cashier getFirstAvailableCashier();
};

#endif