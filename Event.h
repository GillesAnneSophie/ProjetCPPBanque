/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJECT_EVENT_H
#define PROJECT_EVENT_H

class Event{
private:
    double time;

public:
    Event(double time);
    virtual void process() = 0;
    double getTime();
};

#endif