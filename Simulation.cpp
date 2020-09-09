/*
 * @author Anne-Sophie GILLES
 */

#include "Simulation.h"

//TODO voir si ok appel parent
Simulation::Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount) : DiscreteEventSimulation(0) {
    this->plannedDuration = plannedDuration;
    this->averageArrivalTime = averageArrivalTime;
    bank = new Bank(averageServiceTime, cashiersCount);
}

double Simulation::getAverageArrivalTime() {
    return averageArrivalTime;
}

double Simulation::getPlannedDuration() {
    return plannedDuration;
}