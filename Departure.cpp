/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Cashier & cashier, Simulation & simulation) : Event(time) {
    this->simulation = &simulation;
    this->client = &client;
    this->cashier = &cashier;
}

void Departure::process() {
    delete client;
    cashier->free();
}