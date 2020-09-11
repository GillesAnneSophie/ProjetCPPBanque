/*
 * @author Anne-Sophie GILLES
 */

#include "Cashier.h"

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

double Cashier::getAverageServiceTime() {
    return averageServiceTime;
}

double Cashier::getOccupationRate() {
    double rd = bank->getSimulation().getRealDuration();
    return (occupiedTime/rd)*100;
}

bool Cashier::isAvailable() {
    return available;
}

void Cashier::serveClient(Client & client) {
    if(bank->getSimulation().DEBUG){
        cout << "> serveClient()" << endl;
    }

    clientsCount++;
    bank->addClientToCount();

    Poisson::init();
    double random = Poisson::next();
    occupiedTime += random;

    Departure departure(bank->getSimulation().getCurrentTime(), client, *this);
    bank->getSimulation().addEvent(departure);

    if(bank->getSimulation().DEBUG){
        cout << "< serveClient()" << endl;
    }
}

void Cashier::free() {
    if(bank->getSimulation().DEBUG){
        cout << "- free()" << endl;
    }
    available = true;
}

Bank& Cashier::getBank() {
    return *bank;
}