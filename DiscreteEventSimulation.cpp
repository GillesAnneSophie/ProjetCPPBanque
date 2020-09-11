/*
 * @author Anne-Sophie GILLES
 */

#include "DiscreteEventSimulation.h"

#include <iostream>
using namespace std;

DiscreteEventSimulation::DiscreteEventSimulation(double startTime) {
    cout << "> DiscreteEventSimulation()" << endl;

    this->startTime = startTime;
    this->currentTime = startTime;

    cout << "< DiscreteEventSimulation()" << endl;
}

DiscreteEventSimulation::DiscreteEventSimulation(const DiscreteEventSimulation & discreteEventSimulation) {
    this->currentTime = discreteEventSimulation.currentTime;
    this->eventQueue = discreteEventSimulation.eventQueue;
    this->startTime = discreteEventSimulation.startTime;
}

double DiscreteEventSimulation::getCurrentTime() {
    return currentTime;
}

void DiscreteEventSimulation::addEvent(Event & event) {
    cout << "- addEvent()" << endl;
    eventQueue.push(&event);
}
void DiscreteEventSimulation::launch() {
    cout << "> launch()" << endl;

    if(!eventQueue.empty() && eventQueue.top()->getTime() == currentTime){
        eventQueue.top()->process();//TODO PLANTE ICI
        eventQueue.pop();
    }
    else{
        currentTime++;
    }

    cout << "< launch()" << endl;
}