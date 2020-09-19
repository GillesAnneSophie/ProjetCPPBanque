/*
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_EVENT_H
#define PROJECT_EVENT_H

/**
 * Event class, working as a virtual class. Given attribute is :
 * - time : double attribute indicating the time when the event took place
 */
class Event{
private:
    double time;

public:
    /**
     * Event Constructor
     * @param time Double - the arrival or departure time of the client
     */
    explicit Event(double time);
    /**
     * Event Copy-Constructor
     * @param event Event
     */
    Event(const Event & event);
    /**
     * Launch Event's process
     */
    virtual void process() = 0;
    /**
     * Get time
     * @return time Double
     */
    double getTime();
};

#endif