/*
 * @author Anne-Sophie GILLES
 */

#include <iostream>
#include "Simulation.h"

using namespace std;

int main() {
    int plannedDuration = 100;
    int averageArrivalTime = 5;
    int averageServiceTime = 10;
    int cashiersCount = 10;

    cout << "----- Begin Simulation -----" << endl
         << "plannedDuration: " << plannedDuration << endl
         << "averageArrivalTime: " << averageArrivalTime << endl
         << "averageServiceTime: " << averageServiceTime << endl
         << "cashiersCount: " << cashiersCount << endl;

    Simulation simulation(plannedDuration, averageArrivalTime, averageServiceTime, cashiersCount);
    simulation.launch();

    simulation.setRealDuration(simulation.getCurrentTime());

    cout << "----- End Simulation -----" << endl
         << "realDuration: " << simulation.getRealDuration() << endl
         << "total clients count: " << simulation.getBank().getClientsCount() << endl
         << "queue max length: " << simulation.getBank().getQueue().getMaxLength() << endl
         << "queue average length: " << simulation.getBank().getQueue().getAverageLength() << endl
         << "queue average length: " << simulation.getBank().getQueue().getAverageWaitingTime() << endl;

    Bank bank = simulation.getBank();
    for(int i=0 ; i<cashiersCount ; i++){
        Cashier cashier = bank.getCashier(i);
        cout << "Cashier " << i << ": " << endl
             << "\toccupationRate: " << cashier.getOccupationRate() << endl
             << "\tclientsCount: " << cashier.getClientsCount() << endl;
    }

    return 0;
}