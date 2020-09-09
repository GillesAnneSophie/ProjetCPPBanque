/*
 * @author Anne-Sophie GILLES
 */

#ifndef PROJET_EVENT_H
#define PROJET_EVENT_H

class Event{
private:
    double time;

public:
    Event(double time);
    virtual void process() = 0;
    double getTime();
};

#endif