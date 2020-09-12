/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Cashier & cashier) : Event(time) {
    if(cashier.getBank().getSimulation().DEBUG){
        cout << "> Departure()" << endl;
    }

    this->client = &client;
    this->cashier = &cashier;

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

    int occupiedTime = (int) (cashier->getBank().getSimulation().getCurrentTime()-client->getArrivalTime());
    cout << "occupiedTime= " << occupiedTime << endl;
    cashier->addOccupiedTime(occupiedTime);

    delete client;
    cashier->free();

    if(cashier->getBank().getSimulation().DEBUG){
        cout << "< Departure::process()" << endl;
    }
}