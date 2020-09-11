/*
 * @author Anne-Sophie GILLES
 */

#include "Cashier.h"

Cashier::Cashier(double averageServiceTime, Bank & bank) {
    this->bank = &bank;
    this->averageServiceTime = averageServiceTime;
    this->available = true;
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

void Cashier::serveClient(Client client) {
    clientsCount++;
    //TODO random loi de poisson avec un wait() & occupiedTime += rand;
}

void Cashier::free() {
    available = true;
}