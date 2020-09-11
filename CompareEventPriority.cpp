/*
 * @author Anne-Sophie GILLES
 */

#include "CompareEventPriority.h"

#include <iostream>
using namespace std;

int CompareEventPriority::operator()(Event * &e1, Event * &e2) {
    return e1->getTime() > e2->getTime();
}