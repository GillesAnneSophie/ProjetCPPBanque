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
    cout << "- addEvent()" << endl;
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
        eventQueue.pop();

        cout << "\tcurrentTime=" << currentTime << endl
             << "\teventQueue size : " << eventQueue.size() << endl
             << "\teventQueue top time : " << eventQueue.top()->getTime() << endl
             << "\teventQueue top time : " << currentEvent->getTime() << endl;

        if ((int) currentEvent->getTime() == currentTime) {
            currentTime++;
            currentEvent->process();
        } else {
            currentTime++;
            cerr << "\n\tERROR: launch > else: " << currentTime << endl;
        }
    }

#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
}