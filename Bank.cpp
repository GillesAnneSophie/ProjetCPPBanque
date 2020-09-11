/*
 * @author Anne-Sophie GILLES
 */

#include "Bank.h"

Bank::Bank(double averageServiceTime, int cashiersCount) {
    this->cashiersCount = cashiersCount;
    //TODO
    queue = new Queue(this);
    cashiers = new Cashier*[cashiersCount];
    for(int i=0 ; i<cashiersCount ; i++){
        cashiers[i] = new Cashier(averageServiceTime, this);
    }
}

Bank::Bank(const Bank & bank) {
    this->cashiersCount = bank.cashiersCount;
    //TODO
    this->queue = bank.queue;
    this->cashiers = bank.cashiers;
    this->clientsCount = bank.clientsCount;
}

int Bank::getCashiersCount() {
    return cashiersCount;
}

int Bank::getClientsCount() {
    return clientsCount;
}

Cashier Bank::getFirstAvailableCashier() {
    int i = 0;
    while(i < cashiersCount){
        if(cashiers[i]->isAvailable()){
            return *cashiers[i];
        }
        i++;
    }
}

Queue & Bank::getQueue() {
    return *queue;
}