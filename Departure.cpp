/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Cashier & cashier) : Event(time) {
    if(cashier.getBank().getSimulation().DEBUG){
        cout << "> Departure()" << endl;
    }
    cout << "\tDeparture.time=" << time << endl;

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

    delete client;
    cashier->free();

    if(cashier->getBank().getSimulation().DEBUG){
        cout << "< Departure::process()" << endl;
    }
}