/*
 * @author Anne-Sophie GILLES
 */

#include "Arrival.h"

Arrival::Arrival(double time, Simulation & simulation) : Event(time) {
    this->simulation = &simulation;
    this->cashier = nullptr;
    this->client = nullptr;
}

Arrival::Arrival(const Arrival & arrival) : Event(arrival) {
    this->cashier = arrival.cashier;
    this->client = arrival.client;
    this->simulation = arrival.simulation;
}

void Arrival::process() {
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
    double nextTime = simulation->getCurrentTime(); //TODO générer le random avec poisson : random.next(simu.tempsMoyenArrivee);
    if(nextTime <= simulation->getPlannedDuration()){
        Arrival a(nextTime, *simulation);
        simulation->addEvent(a);
    }
}