/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

class Client{
private:
    double arrivalTime;

public:
    /**
     * Client Constructor
     * @param arrivalTime
     */
    explicit Client(double arrivalTime);
    /**
     * Client Copy-Constructor
     * @param client
     */
    Client(const Client & client);
    /**
     * Get arrival time
     * @return arrivalTime
     */
    double getArrivalTime();
};

#endif