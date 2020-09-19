/*
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

/**
 * Client class. Given private attribute is :
 * - arrivalTime Double - the client's time of arrival
 */

class Client{
private:
    double arrivalTime;

public:
    /**
     * Client Constructor
     * @param arrivalTime Double - the client's time of arrival in the bank
     */
    explicit Client(double arrivalTime);
    /**
     * Client Copy-Constructor
     * @param client Client
     */
    Client(const Client & client);
    /**
     * Get arrival time
     * @return arrivalTime Double
     */
    double getArrivalTime();
};

#endif