/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_SIMULATION_H
#define PROJET_SIMULATION_H

class Simulation{
private:
    double plannedDuration;
    double averageArrivalTime;

public:
    Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount);
    double getPlannedDuration();
    double getAverageArrivalTime();
};

#endif