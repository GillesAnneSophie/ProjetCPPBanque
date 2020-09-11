/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Cashier & cashier, Simulation & simulation) : Event(time) {
    this->simulation = &simulation;
    this->client = &client;
    this->cashier = &cashier;
}

Departure::Departure(const Departure & departure) : Event(departure.time) {
    this->simulation = departure.simulation;
    this->client = departure.client;
}

void Departure::process() {
    delete client;
    cashier->free();
}