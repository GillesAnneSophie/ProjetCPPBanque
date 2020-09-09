/*
 * @author Anne-Sophie GILLES
 */

#include "Simulation.h"

Simulation::Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount) {
    this->plannedDuration = plannedDuration;
    this->averageArrivalTime = averageArrivalTime;
    //TODO
}

double Simulation::getAverageArrivalTime() {
    return averageArrivalTime;
}

double Simulation::getPlannedDuration() {
    return plannedDuration;
}