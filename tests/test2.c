/*
 * Approximated functions and initial conditions.
 * Test #1: y = x**3 / 5
 */

/*
 * Initial conditions.
 */
const double a = 0;
const double psi1 = 1; // any value
const double sigma1 = 50; // any value
const double kappa1 = 0;

const double b = 5;
const double psi2 = 0;
const double sigma2 = 2;
const double kappa2 = 30;

double f(double x) {
    return 6 * x / 5 + x * x * x;
}

double p(double x) {
    return 0;
}

double q(double x) {
    return 5;
}