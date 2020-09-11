/*
 * @author Anne-Sophie GILLES
 */

#include "DiscreteEventSimulation.h"

DiscreteEventSimulation::DiscreteEventSimulation(double startTime) {
    this->startTime = startTime;
}

double DiscreteEventSimulation::getCurrentTime() {
    return currentTime;
}

void DiscreteEventSimulation::addEvent(Event & event) {
    eventQueue.push(&event);
}

void DiscreteEventSimulation::launch() {
    //TODO ?
    eventQueue.pop();
}