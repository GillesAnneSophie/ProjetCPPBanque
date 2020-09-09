/*
 * @author Anne-Sophie GILLES
 */

#include "Event.h"

Event::Event(double time) {
    this->time = time;
}

double Event::getTime() {
    return time;
}