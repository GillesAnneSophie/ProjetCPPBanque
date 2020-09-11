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

/*
    Event * e = pq.top();
        cout << "pq.top() = " << pq.top()->getTime()  << endl;
        cout << "e->getTime() = " << e->getTime()  << endl;
        pq.pop();
 * */

void DiscreteEventSimulation::launch() {
#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
    cout << "> launch()" << endl;

    while(!eventQueue.empty()) {
        Event * currentEvent = eventQueue.top();

        cout << "eventQueue.top() = " << this->eventQueue.top()->getTime()  << endl;

        cout << "\tINFO: getTime=" << currentEvent->getTime() << endl;
        cout << "\tINFO: getTime=" << eventQueue.top()->getTime() << endl;
        if (eventQueue.top()->getTime() == currentTime) {
            //cout << "\tINFO: launch > if: " << currentEvent->getTime() << endl;
            //currentEvent->process();
            eventQueue.pop();
        } else {
            cerr << "\tERROR: launch > else: " << currentTime << endl;
        }
        currentTime++;

        if(currentTime >= 10){
            break;
        }
    }

#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
    cout << "< launch()" << endl;
}