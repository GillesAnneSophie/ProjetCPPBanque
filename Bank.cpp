/*
 * @author Anne-Sophie GILLES
 */

#include "Bank.h"

using namespace std;

Bank::Bank(double averageServiceTime, int cashiersCount, Simulation & simulation) {
    if(simulation.DEBUG){
        cout << "> Bank()" << endl;
    }

    this->cashiersCount = cashiersCount;
    this->simulation = &simulation;
    this->clientsCount = 0;
    queue = new Queue(*this);
    cashiers = new Cashier*[cashiersCount];
    for(int i=0 ; i<cashiersCount ; i++){
        cashiers[i] = new Cashier(averageServiceTime, *this);
    }

    if(simulation.DEBUG){
        cout << "< Bank()" << endl;
    }
}

Bank::~Bank() {
    if(simulation->DEBUG){
        cout << "- ~Bank()" << endl;
    }

    delete[] cashiers;
    delete queue;
}

Bank::Bank(const Bank & bank) {
    this->cashiersCount = bank.cashiersCount;
    this->simulation = bank.simulation;
    this->queue = bank.queue;
    this->cashiers = bank.cashiers;
    this->clientsCount = bank.clientsCount;
}

int Bank::getClientsCount() {
    return clientsCount;
}

void Bank::addClientToCount() {
    if(simulation->DEBUG){
        cout << "- addClientToCount()" << endl;
    }
    clientsCount++;
}

Cashier* Bank::getFirstAvailableCashier() {
    if(simulation->DEBUG){
        cout << "- getFirstAvailableCashier()" << endl;
    }

    int i = 0;
    while(i < cashiersCount){
        if(cashiers[i]->isAvailable()){
            if(simulation->DEBUG){
                cout << "\tisAvailable" << endl;
                cout << "\tindex = " << i << endl;
            }
            return cashiers[i];
        }
        i++;
    }
    return nullptr;
}

Queue& Bank::getQueue() {
    return *queue;
}

Simulation& Bank::getSimulation() {
    return *simulation;
}

Cashier& Bank::getCashier(int index) {
    return *cashiers[index];
}