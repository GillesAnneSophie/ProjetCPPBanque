/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

class Client{
private:
    double arrivalTime;

public:
    Client(double arrivalTime);
    Client(const Client & client);
    double getArrivalTime();
};

#endif