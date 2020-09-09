/*
 * @author Anne-Sophie GILLES
 */

#include "Bank.h"

Bank::Bank(double averageServiceTime, int cashiersCount) {
    this->cashiersCount = cashiersCount;
    //TODO
}

int Bank::getCashiersCount() {
    return cashiersCount;
}

int Bank::getClientsCount() {
    return clientsCount;
}

Cashier Bank::getFirstAvailableCashier() {
    //TODO
}