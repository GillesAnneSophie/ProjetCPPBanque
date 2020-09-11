/*
 * @author Anne-Sophie GILLES
 */

#include "Bank.h"

Bank::Bank(double averageServiceTime, int cashiersCount, Simulation * simulation) {
    this->cashiersCount = cashiersCount;
    this->simulation = simulation;
    queue = new Queue(this);
    cashiers = new Cashier*[cashiersCount];
    for(int i=0 ; i<cashiersCount ; i++){
        cashiers[i] = new Cashier(averageServiceTime, *this);
    }
}

Bank::~Bank() {
    delete[] cashiers;
    delete queue;
}

int Bank::getCashiersCount() {
    return cashiersCount;
}

int Bank::getClientsCount() {
    return clientsCount;
}

Cashier* Bank::getFirstAvailableCashier() {
    int i = 0;
    while(i < cashiersCount){
        if(cashiers[i]->isAvailable()){
            return cashiers[i];
        }
        i++;
    }
    return NULL;
}

Queue& Bank::getQueue() {
    return *queue;
}

Simulation& Bank::getSimulation() {
    return *simulation;
}