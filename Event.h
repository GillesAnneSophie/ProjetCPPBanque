/*
 * @author Amaury SIHARATH
 */

#ifndef PROJECT_EVENT_H
#define PROJECT_EVENT_H

class Event{
private:
    double time;

public:
    /**
     * Event Constructor
     * @param time
     */
    explicit Event(double time);
    /**
     * Event Copy-Constructor
     * @param event
     */
    Event(const Event & event);
    /**
     * Launch Event's process
     */
    virtual void process() = 0;
    /**
     * Get time
     * @return time
     */
    double getTime();
};

#endif