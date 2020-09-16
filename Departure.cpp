/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Cashier & cashier, double serviceTime) : Event(time) {
    if(cashier.getBank().getSimulation().DEBUG){
        cout << "> Departure()" << endl;
    }

    this->client = &client;
    this->cashier = &cashier;
    this->serviceTime = serviceTime;
    if(cashier.getBank().getSimulation().DEBUG){
        cout << "< Departure()" << endl;
    }
}

Departure::Departure(const Departure & departure) : Event(departure) {
    this->client = departure.client;
    this->cashier = departure.cashier;
}

void Departure::process() {
    if(cashier->getBank().getSimulation().DEBUG){
        cout << "> Departure::process()" << endl;
    }

    double occupiedTime = (double) this->serviceTime;
    cashier->addOccupiedTime(occupiedTime);

    delete client;
    cashier->free();

    if(cashier->getBank().getSimulation().DEBUG){
        cout << "< Departure::process()" << endl;
    }
}