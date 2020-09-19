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
 * DiscreteEventSimulation class, obviously representing it's purpose. Three given private attributes are :
 * - currentTime : double attribute which is keeping the current time of the Simulation. It is everchanging when simulation is running.
 * - startTime : double attribute indicating the start time of the Simulation. 
 * - eventQueue ! priority_queue<Event*, vector<Event*>, CompareEventPriority> attribute. Events being or going to be processed are kept there.
 */
class DiscreteEventSimulation{
private:
    double currentTime;
    double startTime;
    priority_queue<Event*, vector<Event*>, CompareEventPriority> eventQueue;

public:
    /**
     * DiscreteEventSimulation Constructor.
     * @param startTime Start time of the simulation
     */
    explicit DiscreteEventSimulation(double startTime);
    /**
     * DiscreteEventSimulation Copy-Constructor.
     * @param discreteEventSimulation
     */
    DiscreteEventSimulation(const DiscreteEventSimulation & discreteEventSimulation);
    /**
     * Add the given event to eventQueue.
     * @param event Event to be added. Can be a Departure or Arrival, or any class implementing Event.
     */
    void addEvent(Event * event);
    /**
     * Get current time.
     * @return currentTime as a double value
     */
    double getCurrentTime();
    /**
     * Launch simulation.
     */
    void launch();
};

#endif