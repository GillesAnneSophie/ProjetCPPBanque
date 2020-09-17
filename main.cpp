/*
 * @author Anne-Sophie GILLES
 */

#include <iostream>
#include "Simulation.h"

using namespace std;

int main() {
    int plannedDuration = 1000;
    int averageArrivalTime = 5;
    int averageServiceTime = 15;
    int cashiersCount = 3;

    cout << "----- Begin Simulation -----" << endl
         << "plannedDuration: " << plannedDuration << endl
         << "averageArrivalTime: " << averageArrivalTime << endl
         << "averageServiceTime: " << averageServiceTime << endl
         << "cashiersCount: " << cashiersCount << endl;

    Simulation simulation(plannedDuration, averageArrivalTime, averageServiceTime, cashiersCount);

    cout << "----- Launch Simulation -----" << endl;
    simulation.launch();
    cout << "----- End Launch Simulation -----" << endl;

    simulation.setRealDuration(simulation.getCurrentTime());

    cout << "realDuration: " << simulation.getRealDuration() << endl
         << "total clients count: " << simulation.getBank().getClientsCount() << endl
         << "queue max length: " << simulation.getBank().getQueue().getMaxLength() << endl
         << "queue average length: " << simulation.getBank().getQueue().getAverageLength() << endl
         << "queue average waiting time: " << simulation.getBank().getQueue().getAverageWaitingTime() << endl;

    Bank bank = simulation.getBank();
    for(int i=0 ; i<cashiersCount ; i++){
        Cashier cashier = bank.getCashier(i);
        cout << "Cashier " << i << ": " << endl
             << "\toccupationRate: " << cashier.getOccupationRate() << "%" << endl
             << "\toccupiedTime: " << cashier.getOccupiedTime() << endl
             << "\tclientsCount: " << cashier.getClientsCount() << endl;
    }

    cout << "----- End Simulation -----" << endl;

    return 0;
}