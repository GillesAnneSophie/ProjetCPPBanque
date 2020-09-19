/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_SIMULATION_H
#define PROJECT_SIMULATION_H

#include "Bank.h"
#include "DiscreteEventSimulation.h"
#include "Arrival.h"

class Bank;

/**
 * Simulation class. Given private attributes are :
 * - plannedDuration Double - planned duration for the simulation
 * - realDuration Double - real duration at the end of the simulation
 * - averageArrivalTime Double - average arrival time wanted for the simulation
 * - bank bank - an access to the Bank object
 */
class Simulation : public DiscreteEventSimulation{
private:
    double plannedDuration;
    double realDuration;
    double averageArrivalTime;
    Bank * bank;

public:
    /**
     * Simulation Constructor
     * @param plannedDuration Double - planned duration for the simulation
     * @param averageArrivalTime Double - average arrival time wanted for the simulation
     * @param averageServiceTimes Double[] - average service times wanted for the cashiers
     * @param cashiersCount Int - wanted number of cashiers for the bank
     */
    Simulation(double plannedDuration, double averageArrivalTime, double * averageServiceTimes, int cashiersCount);
    /**
     * Simulation Copy-Constructor
     * @param simulation Simulation
     */
    Simulation(const Simulation & simulation);
    /**
     * Get simulation's planned duration
     * @return plannedDuration Double
     */
    double getPlannedDuration();
    /**
     * Get average arrival time
     * @return averageArrivalTime Double
     */
    double getAverageArrivalTime();
    /**
     * Get bank
     * @return Bank
     */
    Bank & getBank();
    /**
     * Set simulation's real duration
     * @param realDuration Double
     */
    void setRealDuration(double realDuration);
    /**
     * Get simulation's real duration
     * @return realDuration Double
     */
    double getRealDuration();

    bool DEBUG = false;
};

#endif