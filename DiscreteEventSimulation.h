/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_DISCRETE_EVENT_SIMULATION_H
#define PROJECT_DISCRETE_EVENT_SIMULATION_H

#include <iostream>
#include <queue>
#include <vector>
#include "Event.h"
#include "CompareEventPriority.h"

using namespace std;


class DiscreteEventSimulation{
private:
    double currentTime;
    double startTime;
    priority_queue<Event*, vector<Event*>, CompareEventPriority> eventQueue;

public:
    DiscreteEventSimulation(double startTime);
    DiscreteEventSimulation(const DiscreteEventSimulation & discreteEventSimulation);
    void addEvent(Event & event);
    double getCurrentTime();
    void launch();
};

#endif