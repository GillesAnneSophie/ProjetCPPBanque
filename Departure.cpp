/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Simulation & simulation) : Event(time) {
    this->simulation = &simulation;
    this->client = &client;
}

Departure::Departure(const Departure & departure) : Event(departure.time) {
    this->simulation = departure.simulation;
    this->client = departure.client;
}

void Departure::process() {
    //TODO

}