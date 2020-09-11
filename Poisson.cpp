#include <cmath>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include "Poisson.h"

void Poisson::init(int seed) {
    srandom(seed ? seed : getpid()); 
}

double Poisson::next(double moy) {
    return -log(((double)random()/RAND_MAX))*moy;
}