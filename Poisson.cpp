#ifndef __Poisson_h
#define __Poisson_h

/*******************************
 * Generateur aleatoire de nombre reels positifs suivant une loi de Poisson.
 * la loyenne est fixee par le parametre de la methode de classe next().
 * par defaut, la moyenne est 1.0
 *******************************/

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "Poisson.h"

static void Poisson::init(int seed = 0) {
    srandom(seed ? seed : getpid()); 
}

static double Poisson::next(double moy = 1.0) {
    return -log(((double)random()/RAND_MAX))*moy;
}

#endif