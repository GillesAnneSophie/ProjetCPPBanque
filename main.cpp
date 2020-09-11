/*
 * @author Anne-Sophie GILLES
 */

#include <iostream>
#include "Simulation.h"

using namespace std;

int main() {
    cout << "Begin Simulation" << endl;

    Simulation simulation(100, 5, 10, 10);
    simulation.setRealDuration(simulation.getCurrentTime());

    cout << "RealDuration=" << simulation.getRealDuration() << endl;

    return 0;
}