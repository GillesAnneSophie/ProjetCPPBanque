/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_SIMULATION_H
#define PROJECT_SIMULATION_H

#include "Bank.h"
#include "DiscreteEventSimulation.h"
#include "Arrival.h"

class Bank;

class Simulation : public DiscreteEventSimulation{
private:
    double plannedDuration;
    double realDuration;
    double averageArrivalTime;
    Bank * bank;

public:
    Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount);
    Simulation(const Simulation & simulation);
    double getPlannedDuration();
    double getAverageArrivalTime();
    Bank & getBank();
    void setRealDuration(double realDuration);
    double getRealDuration();

    bool DEBUG = true;
};

#endif