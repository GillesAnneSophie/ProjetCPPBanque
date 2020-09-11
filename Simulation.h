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
    /**
     * Simulation Constructor
     * @param plannedDuration
     * @param averageArrivalTime
     * @param averageServiceTime
     * @param cashiersCount
     */
    Simulation(int plannedDuration, double averageArrivalTime, double averageServiceTime, int cashiersCount);
    /**
     * Simulation Copy-Constructor
     * @param simulation
     */
    Simulation(const Simulation & simulation);
    /**
     * Get simulation's planned duration
     * @return plannedDuration
     */
    double getPlannedDuration();
    /**
     * Get average arrival time
     * @return averageArrivalTime
     */
    double getAverageArrivalTime();
    /**
     * Get bank
     * @return bank
     */
    Bank & getBank();
    /**
     * Set simulation's real duration
     * @param realDuration
     */
    void setRealDuration(double realDuration);
    /**
     * Get simulation's real duration
     * @return realDuration
     */
    double getRealDuration();

    bool DEBUG = true;
};

#endif