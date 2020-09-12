/*
 * @author Anne-Sophie GILLES
 */

#include "DiscreteEventSimulation.h"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

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
#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif

    while(!eventQueue.empty()) {
        Event * currentEvent = eventQueue.top();

        cout << "\tcurrentTime=" << currentTime << endl
             << "\teventQueue size : " << eventQueue.size() << endl
             << "\teventQueue top time : " << (currentEvent->getTime()) << endl;

        if (currentEvent->getTime() == currentTime) {
            currentEvent->process();
            eventQueue.pop();
            currentEvent = eventQueue.top();

            if(currentEvent->getTime() != currentTime) {
                currentTime++;
            }
        } else {
            currentTime++;
            cerr << "Error: nothing to do now: " << currentTime << endl;
        }
    }

#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
}