/*
 * @author Anne-Sophie GILLES
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_CASHIER_H
#define PROJECT_CASHIER_H

#include "Bank.h"
#include "Client.h"
#include "Departure.h"

class Bank;

/**
 * Object representing a Cashier. Given private parameters are :
 * - averageServiceTime : A double variable for the average service time, that should be configured with the Simulation class
 * - clientsCount : An integer representing the number of clients served by the cashier
 * - bank : A pointer on a Bank object for easy access
 * - available : A boolean variable to indicate the occupancy of the cashier
 * - occupiedTime : A double variable totalling the amount time the cashier was occupied during the simulation
*/
class Cashier{
private:
    double averageServiceTime;
    int clientsCount;
    Bank * bank;
    bool available;
    double occupiedTime;

public:
    /**
     * Cashier Constructor.
     * @param averageServiceTime The average service time of the cashier.
     * @param bank The bank in which the cashier is part of.
     */
    Cashier(double averageServiceTime, Bank & bank);
    /**
     * Cashier Copy-Constructor.
     * @param cashier
     */
    Cashier(const Cashier & cashier);
    /**
     * Get clients count.
     * @return clientsCount as an Integer value.
     */
    int getClientsCount();
    /**
     * Get occupation rate. The rate is calculated by using the formula : (occupiedTime*100.00)/ realDuration. Result is given in percentage.
     * @return occupationRate as a double value.
     */
    double getOccupationRate();
    /**
     * Get available attribute.
     * @return available as a boolean value. 
     * - Returns true if cashier isn't occupied
     * - Return false if occupied
     */
    bool isAvailable();
    /**
     * Serve the given client.
     * @param client A Client object.
     */
    void serveClient(Client & client);
    /**
     * Set available attribute to true
     */
    void free();
    /**
     * Get bank attribute.
     * @return bank reference.
     */
    Bank & getBank();
    /**
     * Add given occupied time to occupiedTime attribute.
     * @param time
     */
    void addOccupiedTime(double time);
    /**
     * Get occupied time attribute.
     * @return occupiedTime as double value.
     */
    double getOccupiedTime();
};

#endif