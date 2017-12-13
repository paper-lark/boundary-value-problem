/*
 * Approximated functions and initial conditions.
 * Test #1: y = cos(3x)
 */

#include <math.h>

/*
 * Initial conditions.
 */
const double a = 0;
const double psi1 = 3; // any value
const double sigma1 = 50; // any value
const double kappa1 = 3;

const double b = 1.5708;
const double psi2 = 0; // any value
const double sigma2 = 1;
const double kappa2 = 3;

double f(double x) {
    return x * sin(3 * x);
}

double p(double x) {
    return -x / 3;
}

double q(double x) {
    return 9;
}