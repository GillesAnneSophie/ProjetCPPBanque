/*
 * @author Anne-Sophie GILLES
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_DISCRETE_EVENT_SIMULATION_H
#define PROJECT_DISCRETE_EVENT_SIMULATION_H

#include <iostream>
#include <queue>
#include <vector>
#include "Event.h"
#include "CompareEventPriority.h"

using namespace std; 

/**
 * DiscreteEventSimulation class. Given private attributes are :
 * - currentTime Double - the current time of the simulation
 * - startTime Double - the start time of the simulation
 * - eventQueue priority_queue<Event*, vector<Event*>, CompareEventPriority> - Queue of all simulation's events to be processed
 */
class DiscreteEventSimulation{
private:
    double currentTime;
    double startTime;
    priority_queue<Event*, vector<Event*>, CompareEventPriority> eventQueue;

public:
    /**
     * DiscreteEventSimulation Constructor
     * @param startTime Double - start time of the simulation
     */
    explicit DiscreteEventSimulation(double startTime);
    /**
     * DiscreteEventSimulation Copy-Constructor
     * @param discreteEventSimulation DiscreteEventSimulation
     */
    DiscreteEventSimulation(const DiscreteEventSimulation & discreteEventSimulation);
    /**
     * Add the given event to eventQueue
     * @param event Event
     */
    void addEvent(Event * event);
    /**
     * Get current time
     * @return currentTime Double
     */
    double getCurrentTime();
    /**
     * Launch simulation
     */
    void launch();
};

#endif