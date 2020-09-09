/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_SIMULATION_H
#define PROJECT_SIMULATION_H

#include "Bank.h"
#include "DiscreteEventSimulation.h"

class Simulation : public DiscreteEventSimulation{
private:
    double plannedDuration;
    double averageArrivalTime;
    Bank * bank;

public:
    Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount);
    double getPlannedDuration();
    double getAverageArrivalTime();
};

#endif