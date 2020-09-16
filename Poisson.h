#ifndef PROJECT_POISSON_H
#define PROJECT_POISSON_H

class Poisson {
public:
    /**
     * Initialise Poisson's Law
     * @param seed
     */
    static void init(int seed = 0);
    /**
     * Get a random following Poisson's Law
     * @param moy
     * @return random
     */
    static double next(double moy = 1.0);
};

#endif