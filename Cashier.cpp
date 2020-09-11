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

double Cashier::getOccupationRate() {
    double rd = bank->getSimulation().getRealDuration();
    return (occupiedTime*100)/rd;
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
    double random = Poisson::next(averageServiceTime);
    occupiedTime += random;

    bank->getSimulation().addEvent(new Departure(bank->getSimulation().getCurrentTime(), client, *this));

    if(bank->getSimulation().DEBUG){
        cout << "\tpriorityQueue / eventQueue size : " << bank->getSimulation().eventQueue.size() << endl;
    }

    if(bank->getSimulation().DEBUG){
        cout << "\tDeparture" << endl;
    }

    if(bank->getSimulation().DEBUG){
        cout << "< serveClient()" << endl;
    }

    if(!bank->getQueue().isEmpty()){
        Client newClient = bank->getQueue().remove();
        this->serveClient(newClient);
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