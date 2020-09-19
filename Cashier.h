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
 * Cashier class. Given private attributes are :
 * - averageServiceTime Double - the average service time of the cashier
 * - clientsCount Int - the number of clients served by the cashier
 * - bank Bank - an access to the Bank object
 * - available Boolean - the cashier's availability
 * - occupiedTime Double - the total amount of occupied time of the cashier during the simulation
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
     * Cashier Constructor
     * @param averageServiceTime Double - the average service time of the cashier
     * @param bank Bank - the bank in which the cashier is part of
     */
    Cashier(double averageServiceTime, Bank & bank);
    /**
     * Cashier Copy-Constructor
     * @param cashier Cashier
     */
    Cashier(const Cashier & cashier);
    /**
     * Get clients count
     * @return clientsCount Int
     */
    int getClientsCount();
    /**
     * Get occupation rate. The rate is calculated by using the formula : (occupiedTime*100.00)/realDuration. Result is given in percentages
     * @return occupationRate Double
     */
    double getOccupationRate();
    /**
     * Get available attribute
     * @return Boolean - according to cashier's availability
     */
    bool isAvailable();
    /**
     * Serve the given client
     * @param client Client
     */
    void serveClient(Client & client);
    /**
     * Set available attribute to true
     */
    void free();
    /**
     * Get bank attribute
     * @return Bank
     */
    Bank & getBank();
    /**
     * Get occupied time attribute
     * @return occupiedTime Double
     */
    double getOccupiedTime();
};

#endif