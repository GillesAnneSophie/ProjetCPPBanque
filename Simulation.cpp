/*
 * @author Anne-Sophie GILLES
 */

#include "Simulation.h"

Simulation::Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount) : DiscreteEventSimulation(0) {
    bank = new Bank(averageServiceTime, cashiersCount, this);
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

Bank & Simulation::getBank() {
    return *bank;
}

void Simulation::setRealDuration(double realDuration) {
    this->realDuration = realDuration;
}

double Simulation::getRealDuration() {
    return realDuration;
}