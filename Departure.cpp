/*
 * @author Anne-Sophie GILLES
 */

#include "Departure.h"

Departure::Departure(double time, Client & client, Simulation & simulation) : Event(time) {
    this->simulation = &simulation;
    this->client = &client;
}

void Departure::process() {
    //TODO

}