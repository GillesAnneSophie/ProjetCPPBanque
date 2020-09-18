/*
 * @author Amaury SIHARATH
 */

#include "Event.h"

Event::Event(double time) {
    this->time = time;
}

Event::Event(const Event & event) {
    this->time = event.time;
}

double Event::getTime() {
    return time;
}