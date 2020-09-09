/*
 * @author Anne-Sophie GILLES
 */

#include "Arrival.h"

Arrival::Arrival(double time, Cashier & cashier, Client & client) : Event(time) {
    this->cashier = &cashier;
    this->client = &client;
}

void Arrival::process() {
    //TODO
}