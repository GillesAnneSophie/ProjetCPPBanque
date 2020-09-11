/*
 * @author Anne-Sophie GILLES
 */

#include "Client.h"

Client::Client(double arrivalTime) {
    this->arrivalTime = arrivalTime;

}

Client::Client(const Client & clientObj) {
    this->arrivalTime = clientObj.arrivalTime;
}

double Client::getArrivalTime() {
    return arrivalTime;
}