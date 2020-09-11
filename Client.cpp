/*
 * @author Anne-Sophie GILLES
 */

#include "Client.h"

#include <iostream>
using namespace std;

Client::Client(double arrivalTime) {
    cout << "- Client()" << endl;

    this->arrivalTime = arrivalTime;
}

Client::Client(const Client & clientObj) {
    this->arrivalTime = clientObj.arrivalTime;
}

double Client::getArrivalTime() {
    return arrivalTime;
}