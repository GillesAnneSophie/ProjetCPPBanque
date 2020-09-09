/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_CASHIER_H
#define PROJET_CASHIER_H

#include "Bank.h"

class Cashier{
private:
    double averageServiceTime;
    int clientsCount;
    Bank bank;
    bool available;

public:
    Cashier(double averageServiceTime, Bank bank);
    double getAverageServiceTime();
    int getClientsCount();
    double getOccupationRate();
    bool isAvailable();
    void serveClient();
    void freeClient();
};

#endif