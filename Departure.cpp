/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Cashier & cashier) : Event(time) {
    this->client = &client;
    this->cashier = &cashier;
}

Departure::Departure(const Departure & departure) : Event(departure) {
    this->client = departure.client;
    this->cashier = departure.cashier;
}

void Departure::process() {
    delete client;
    cashier->free();
}