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
     * @param plannedDuration Planned Duration for the simulation
     * @param averageArrivalTime Average arrival time wanted for the simulation
     * @param averageServiceTimes Average service time wanted for the cashier
     * @param cashiersCount Wanted number of cashiers for the bank
     */
    Simulation(double plannedDuration, double averageArrivalTime, double * averageServiceTimes, int cashiersCount);
    /**
     * Simulation Copy-Constructor
     * @param simulation
     */
    Simulation(const Simulation & simulation);
    /**
     * Get simulation's planned duration.
     * @return plannedDuration as a double value
     */
    double getPlannedDuration();
    /**
     * Get average arrival time.
     * @return averageArrivalTime as a double value
     */
    double getAverageArrivalTime();
    /**
     * Get bank.
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

    bool DEBUG = false;
};

#endif