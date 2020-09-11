/*
 * @author Anne-Sophie GILLES
 */

#include "CompareEventPriority.h"

#include <iostream>
using namespace std;

int CompareEventPriority::operator()(Event * &e1, Event * &e2) {
    cout << "- CompareEventPriority::operator()" << endl;

    return e1->getTime() > e2->getTime();
}