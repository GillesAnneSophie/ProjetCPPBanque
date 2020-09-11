/*
 * @author Anne-Sophie GILLES
 */

#include "Simulation.h"

//TODO voir si ok appel parent
Simulation::Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount) : DiscreteEventSimulation(0) {
    bank = new Bank(averageServiceTime, cashiersCount);
    this->plannedDuration = plannedDuration;
    this->averageArrivalTime = averageArrivalTime;
}

double Simulation::getAverageArrivalTime() {
    return averageArrivalTime;
}

double Simulation::getPlannedDuration() {
    return plannedDuration;
}

Bank & Simulation::getBank() {
    return *bank;
}