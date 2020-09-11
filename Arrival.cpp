/*
 * @author Anne-Sophie GILLES
 */

#include "Arrival.h"

#include <iostream>
using namespace std;

Arrival::Arrival(double time, Simulation & simulation) : Event(time) {
    if(simulation.DEBUG) {
        cout << "> Arrival()" << endl;
    }
    cout << "\tDeparture.time=" << time << endl;

    this->simulation = &simulation;
    this->cashier = nullptr;
    this->client = nullptr;

    if(simulation.DEBUG) {
        cout << "< Arrival()" << endl;
    }
}

Arrival::Arrival(const Arrival & arrival) : Event(arrival) {
    this->cashier = arrival.cashier;
    this->client = arrival.client;
    this->simulation = arrival.simulation;
}

void Arrival::process() {
    if(simulation->DEBUG) {
        cout << "> Arrival::process()" << endl;
    }

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
        simulation->addEvent(new Arrival(nextTime, *simulation));
    }

    if(simulation->DEBUG) {
        cout << "< Arrival::process()" << endl;
    }
}