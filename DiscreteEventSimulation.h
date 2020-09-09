/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_DISCRETEEVENTSIMULATION_H
#define PROJET_DISCRETEEVENTSIMULATION_H

#include <iostream>
#include <queue>
#include "Event.h"
#include "CompareEventPriority.h"

using namespace std;


class DiscreteEventSimulation{
private:
    double currentTime;
    double startTime;
    priority_queue<Event, CompareEventPriority> eventQueue;

public:
    DiscreteEventSimulation(double startTime);
    void addEvent(Event event);
    double getCurrentTime();
    void launch();
};

#endif