/*
 * @author Anne-Sophie GILLES
 */

#include "Cashier.h"

Cashier::Cashier(double averageServiceTime, Bank bank) {
    this->bank = bank;
    this->averageServiceTime = averageServiceTime;
}

int Cashier::getClientsCount() {
    return clientsCount;
}

double Cashier::getAverageServiceTime() {
    return averageServiceTime;
}

double Cashier::getOccupationRate() {
    //TODO
}

bool Cashier::isAvailable() {
    return available;
}

void Cashier::serveClient() {
    //TODO
}

void Cashier::freeClient() {
    //TODO
}