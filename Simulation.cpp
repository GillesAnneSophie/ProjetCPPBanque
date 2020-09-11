/*
 * @author Anne-Sophie GILLES
 */

#include "Simulation.h"

#include <iostream>
using namespace std;

Simulation::Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount) : DiscreteEventSimulation(0) {
    if(DEBUG){
        cout << "> Simulation()" << endl;
    }

    bank = new Bank(averageServiceTime, cashiersCount, *this);
    this->plannedDuration = plannedDuration;
    this->averageArrivalTime = averageArrivalTime;
    this->realDuration = plannedDuration;

    this->addEvent(new Arrival(0, *this));

    if(DEBUG){
        cout << "< Simulation()" << endl;
    }
}

Simulation::Simulation(const Simulation & simulation) : DiscreteEventSimulation(0) {
    this->averageArrivalTime = simulation.averageArrivalTime;
    this->bank = simulation.bank;
    this->plannedDuration = simulation.plannedDuration;
    this->realDuration = simulation.realDuration;
}

double Simulation::getAverageArrivalTime() {
    if(DEBUG){
        cout << "- getAverageArrivalTime()" << endl;
    }
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