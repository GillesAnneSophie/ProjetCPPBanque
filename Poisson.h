#ifndef PROJECT_POISSON_H
#define PROJECT_POISSON_H

class Poisson {
public:
    static void init(int seed = 0);
    static double next(double moy = 1.0);
};

#endif