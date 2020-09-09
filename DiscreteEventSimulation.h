/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_DISCRETEEVENTSIMULATION_H
#define PROJET_DISCRETEEVENTSIMULATION_H

#include <iostream>
#include <queue>
#include "Event.h"

using namespace std;


class DiscreteEventSimulation{
private:
    double currentHour;
    double startTime;
    priority_queue<Event> eventQueue;

public:
    DiscreteEventSimulation(double startTime);
    void addEvent(Event event);
    double getCurrentHour();
    void launch();
};

#endif