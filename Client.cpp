/*
 * @author Anne-Sophie GILLES
 */

#include "Client.h"

#include <iostream>
using namespace std;

Client::Client(double arrivalTime) {
    cout << "> Client()" << endl;
    this->arrivalTime = arrivalTime;
    cout << "< Client()" << endl;
}

Client::Client(const Client & clientObj) {
    this->arrivalTime = clientObj.arrivalTime;
}

double Client::getArrivalTime() {
    return arrivalTime;
}

double Client::setArrivalTime(double arrivalTime) {
    this->arrivalTime = arrivalTime;
}