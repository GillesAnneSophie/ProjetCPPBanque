/*
 * @author Anne-Sophie GILLES
 * @author Amaury SIHARATH
 */

#include "Cashier.h"

#include <cmath>

Cashier::Cashier(double averageServiceTime, Bank & bank) {
    if(bank.getSimulation().DEBUG){
        cout << "> Cashier()" << endl;
    }

    this->bank = &bank;
    this->averageServiceTime = averageServiceTime;
    this->available = true;
    clientsCount = 0;
    occupiedTime = 0;

    if(bank.getSimulation().DEBUG){
        cout << "< Cashier()" << endl;
    }
}

Cashier::Cashier(const Cashier & cashier) {
    this->bank = cashier.bank;
    this->averageServiceTime = cashier.averageServiceTime;
    this->available = cashier.available;
    this->clientsCount = cashier.clientsCount;
    this->occupiedTime = cashier.occupiedTime;
}

int Cashier::getClientsCount() {
    return clientsCount;
}

double Cashier::getOccupationRate() {
    double rd = bank->getSimulation().getRealDuration();
    return (occupiedTime*100.00)/rd;
}

bool Cashier::isAvailable() {
    return available;
}

void Cashier::serveClient(Client & client) {
    if(bank->getSimulation().DEBUG){
        cout << "> serveClient()" << endl;
    }

    this->available = false;
    clientsCount++;

    Poisson::init(rand());
    double random = Poisson::next(averageServiceTime);
    double currentOccupiedTime = ceil(random);
    double nextTime = bank->getSimulation().getCurrentTime() + currentOccupiedTime;

    occupiedTime += currentOccupiedTime;
    
    bank->getSimulation().addEvent(new Departure(nextTime, client, *this));

    if(bank->getSimulation().DEBUG){
        cout << "< serveClient()" << endl;
    }
}

void Cashier::free() {
    if(bank->getSimulation().DEBUG){
        cout << "- Cashier::free()" << endl;
    }
    available = true;

    if(!bank->getQueue().isEmpty()){
        Client * newClient = bank->getQueue().remove();
        this->serveClient(*newClient);
    }
}

Bank& Cashier::getBank() {
    return *bank;
}

double Cashier::getOccupiedTime() {
    return occupiedTime;
}