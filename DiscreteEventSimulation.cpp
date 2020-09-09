/*
 * @author Anne-Sophie GILLES
 */

#include "DiscreteEventSimulation.h"

DiscreteEventSimulation::DiscreteEventSimulation(double startTime) {
    this->startTime = startTime;
}

double DiscreteEventSimulation::getCurrentHour() {
    return currentHour;
}

void DiscreteEventSimulation::addEvent(Event event) {
    //eventQueue.push()
}

void DiscreteEventSimulation::launch() {
    //TODO
}