/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_CASHIER_H
#define PROJECT_CASHIER_H

#include "Bank.h"
#include "Client.h"
#include "Departure.h"

class Bank;

class Cashier{
private:
    double averageServiceTime;
    int clientsCount;
    Bank * bank;
    bool available;
    double occupiedTime;

public:
    Cashier(double averageServiceTime, Bank & bank);
    Cashier(const Cashier & cashier);
    double getAverageServiceTime();
    int getClientsCount();
    double getOccupationRate();
    bool isAvailable();
    void serveClient(Client & client);
    void free();
    Bank & getBank();
};

#endif