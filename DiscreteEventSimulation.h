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
    /**
     * DiscreteEventSimulation Constructor
     * @param startTime
     */
    DiscreteEventSimulation(double startTime);
    /**
     * DiscreteEventSimulation Copy-Constructor
     * @param discreteEventSimulation
     */
    DiscreteEventSimulation(const DiscreteEventSimulation & discreteEventSimulation);
    /**
     * Add the given event to eventQueue
     * @param event
     */
    void addEvent(Event * event);
    /**
     * Get current time
     * @return currentTime
     */
    double getCurrentTime();
    /**
     * Launch simulation
     */
    void launch();
};

#endif