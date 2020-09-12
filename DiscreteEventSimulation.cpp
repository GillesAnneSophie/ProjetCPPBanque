/*
 * @author Anne-Sophie GILLES
 */

#include "DiscreteEventSimulation.h"
#include <cmath>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class Departure;
class Arrival;

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return is_base_of<Base, T>::value;
}

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

    Event * currentEvent = eventQueue.top();

    while(!eventQueue.empty()) {
        //Event * currentEvent = eventQueue.top();
        //cout << "\tcurrentEvent instanceof<Arrival> =" << instanceof<Arrival>(currentEvent) << endl;
        //cout << "\tcurrentEventType instanceof<Departure> =" << instanceof<Departure>(currentEvent) << endl;
        //cout << "\tcurrentEventType instanceof<Event> =" << instanceof<Event>(currentEvent) << endl;

        cout << "\tcurrentTime=" << currentTime << endl
             << "\teventQueue size : " << eventQueue.size() << endl
             << "\teventQueue top time : " << eventQueue.top()->getTime() << endl
             << "\teventQueue top time : " << (currentEvent->getTime()) << endl;

        //eventQueue.pop();
        if ((int) currentEvent->getTime() == currentTime) {
            //currentTime++;
            currentEvent->process();
            eventQueue.pop();

            currentEvent = eventQueue.top();
            /*
            while((!eventQueue.empty()) && (currentEvent->getTime() == currentTime)) {
                currentEvent->process();
                eventQueue.pop();

                currentEvent = eventQueue.top();
            }
            */
            
            if(currentEvent->getTime() != currentTime) {
                currentTime++;
            } 
            
            /*else {
                currentTime++;
            }*/
        } else {
            currentTime++;
            cout << "\tcurrent Queue Size =" << eventQueue.size() << endl;
            cerr << "\n\tERROR: launch > else: " << currentTime << endl;

            if (currentTime > 30) {
                cerr << "\n\tERROR: INFINITE LOOP : " << currentTime << endl;
                eventQueue.pop();
            }
            //eventQueue.pop();
        }
        /*
        if((int) currentEvent->getTime() < currentTime) {
            cerr << "\n\tERROR: FUCKED currentEvent->getTime() : " << (int) currentEvent->getTime() << endl;
            cerr << "\n\tERROR: FUCKED currentTime : " << currentTime << endl;
            //eventQueue.pop();
        }
        */
    }

#ifdef _WIN32
    Sleep(5000);
#else
    sleep(5);
#endif
}