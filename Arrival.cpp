/*
 * @author Anne-Sophie GILLES
 */

#include "Arrival.h"

#include <iostream>
using namespace std;

Arrival::Arrival(double time, Simulation & simulation) : Event(time) {
    cout << "> Arrival()" << endl;

    this->simulation = &simulation;
    this->cashier = nullptr;
    this->client = nullptr;

    cout << "< Arrival()" << endl;
}

Arrival::Arrival(const Arrival & arrival) : Event(arrival) {
    this->cashier = arrival.cashier;
    this->client = arrival.client;
    this->simulation = arrival.simulation;
}

void Arrival::process() {
    cout << "> Arrival::process()" << endl;

    Client client1(simulation->getCurrentTime());
    this->client = &client1;
    Cashier* cashier1 = simulation->getBank().getFirstAvailableCashier();

    if(cashier1 != nullptr){
        this->cashier = cashier1;
        cashier1->serveClient(client1);
    }
    else{
        simulation->getBank().getQueue().addClient(client1);
    }

    Poisson::init();
    double random = Poisson::next(simulation->getAverageArrivalTime());
    double nextTime = simulation->getCurrentTime() + random;
    if(nextTime <= simulation->getPlannedDuration()){
        Arrival a(nextTime, *simulation);
        simulation->addEvent(a);
    }

    cout << "< Arrival::process()" << endl;
}