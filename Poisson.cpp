#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include "Poisson.h"

void Poisson::init(int seed) {
    srand(seed ? seed : getpid());
}

double Poisson::next(double moy) {
    return -log(((double)rand()/RAND_MAX))*moy;
}