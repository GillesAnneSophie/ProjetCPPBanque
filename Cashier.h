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

class Cashier{
private:
    double averageServiceTime;
    int clientsCount;
    Bank * bank;
    bool available;
    double occupiedTime;

public:
    /**
     * Cashier Constructor
     * @param averageServiceTime
     * @param bank
     */
    Cashier(double averageServiceTime, Bank & bank);
    /**
     * Cashier Copy-Constructor
     * @param cashier
     */
    Cashier(const Cashier & cashier);
    /**
     * Get clients count
     * @return clientsCount
     */
    int getClientsCount();
    /**
     * Get occupation rate
     * @return occupationRate
     */
    double getOccupationRate();
    /**
     * Get available
     * @return available
     */
    bool isAvailable();
    /**
     * Serve the given client
     * @param client
     */
    void serveClient(Client & client);
    /**
     * Set available
     */
    void free();
    /**
     * Get bank
     * @return bank
     */
    Bank & getBank();
    /**
     * Add given occupied time to occupiedTime
     * @param time
     */
    void addOccupiedTime(double time);
    /**
     * Get occupied time
     * @return occupiedTime
     */
    double getOccupiedTime();
};

#endif