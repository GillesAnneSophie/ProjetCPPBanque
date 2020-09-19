#ifndef PROJECT_POISSON_H
#define PROJECT_POISSON_H

class Poisson {
public:
    /**
     * Initialise Poisson's Law
     * @param seed Int
     */
    static void init(int seed = 0);
    /**
     * Get a random following Poisson's Law
     * @param moy Double
     * @return random Double
     */
    static double next(double moy = 1.0);
};

#endif