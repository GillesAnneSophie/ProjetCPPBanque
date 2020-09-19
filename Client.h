/*
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

/**
 * Class representing a client. A client is essentially caracterized by :
 * - arrivalTime : double attribute that is given when a client is created, representing it's time of arrival. 
 */

class Client{
private:
    double arrivalTime;

public:
    /**
     * Client Constructor.
     * @param arrivalTime The client's time of arrival in the bank.
     */
    explicit Client(double arrivalTime);
    /**
     * Client Copy-Constructor.
     * @param client
     */
    Client(const Client & client);
    /**
     * Get arrival time
     * @return arrivalTime attribute as a double value. 
     */
    double getArrivalTime();
};

#endif