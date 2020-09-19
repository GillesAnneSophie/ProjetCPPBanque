/*
 * @author Anne-Sophie GILLES
 */

#include <iostream>
#include <cstring>
#include "Simulation.h"

using namespace std;

int main(int argc, char ** argv) {
    double plannedDuration = 1000;
    double averageArrivalTime = 5;
    int cashiersCount = 3;
    auto * averageServiceTimes = new double[cashiersCount];
    for (int j=0 ; j<cashiersCount ; j++) {
        averageServiceTimes[j] = 15;
    }

    int i = 1;
    while (argv[i]) {
        if (!strcmp(argv[i], "-dp")) {
            sscanf(argv[i+1], "%lf", &plannedDuration);
        }
        else if (!strcmp(argv[i], "-nc")) {
            sscanf(argv[i+1], "%d", &cashiersCount);
            delete [] averageServiceTimes;
            averageServiceTimes = new double[cashiersCount];
            for (int j=0; j<cashiersCount; j++) {
                averageServiceTimes[j] = 15;
            }
        }
        else if (!strcmp(argv[i], "-ta")) {
            sscanf(argv[i+1], "%lf", &averageArrivalTime);
        }
        else if (!strcmp(argv[i], "-ts")) {
            averageServiceTimes = new double[cashiersCount];
            for (int j=0 ; j<cashiersCount ; j++) {
                sscanf(argv[i+1+j], "%lf", &averageServiceTimes[j]);
            }
            i += cashiersCount-1;
        }
        else {
            cerr << "Usage: " << *argv
                 << " [ -dp plannedDuration ] [[ -nc cashiersCount ] -ts serviceTime1...serviceTimeN ] [ -ta arrivalTime ]\n";
            exit(1);
        }
        i += 2;
    }


    cout << "----- Begin Simulation -----" << endl
         << "plannedDuration: " << plannedDuration << endl
         << "averageArrivalTime: " << averageArrivalTime << endl
         << "cashiersCount: " << cashiersCount << endl
         << "averageServiceTime: ";
    for (int j=0 ; j<cashiersCount ; j++) {
        cout << averageServiceTimes[j] << " ";
    }
    cout << endl;

    Simulation simulation(plannedDuration, averageArrivalTime, averageServiceTimes, cashiersCount);

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
    for(int j=0 ; j<cashiersCount ; j++){
        Cashier cashier = bank.getCashier(j);
        cout << "Cashier " << j << ": " << endl
             << "\toccupationRate: " << cashier.getOccupationRate() << "%" << endl
             << "\toccupiedTime: " << cashier.getOccupiedTime() << endl
             << "\tclientsCount: " << cashier.getClientsCount() << endl;
    }

    cout << "----- End Simulation -----" << endl;

    return 0;
}