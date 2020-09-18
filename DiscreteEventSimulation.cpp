/*
 * @author Anne-Sophie GILLES
 * @author Amaury SIHARATH
 */

#include "DiscreteEventSimulation.h"

DiscreteEventSimulation::DiscreteEventSimulation(double startTime) {
    this->startTime = startTime;
    this->currentTime = startTime;
}

DiscreteEventSimulation::DiscreteEventSimulation(const DiscreteEventSimulation & discreteEventSimulation) {
    this->currentTime = discreteEventSimulation.currentTime;
    this->eventQueue = discreteEventSimulation.eventQueue;
    this->startTime = discreteEventSimulation.startTime;
}

double DiscreteEventSimulation::getCurrentTime() {
    return currentTime;
}

void DiscreteEventSimulation::addEvent(Event * event) {
    eventQueue.push(event);
}

void DiscreteEventSimulation::launch() {
    while(!eventQueue.empty()) {
        Event * currentEvent = eventQueue.top();

        if (currentEvent->getTime() == currentTime) {
            currentEvent->process();
            eventQueue.pop();
            currentEvent = eventQueue.top();

            if(currentEvent->getTime() != currentTime) {
                currentTime++;
            }
        } else {
            currentTime++;
        }
    }
}