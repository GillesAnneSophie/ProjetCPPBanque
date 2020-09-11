/*
 * @author Anne-Sophie GILLES
 */

#include "Event.h"

#include <iostream>
using namespace std;

Event::Event(double time) {
    cout << "- Event()" << endl;

    this->time = time;
}

Event::Event(const Event & event) {
    this->time = event.time;
}

double Event::getTime() {
    return time;
}