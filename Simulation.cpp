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

Simulation::Simulation(const Simulation & simulation) : DiscreteEventSimulation(0) {
    this->averageArrivalTime = simulation.averageArrivalTime;
    this->bank = simulation.bank;
    this->plannedDuration = simulation.plannedDuration;

}

double Simulation::getAverageArrivalTime() {
    return averageArrivalTime;
}

double Simulation::getPlannedDuration() {
    return plannedDuration;
}