/*
 * Approximated functions and initial conditions.
 */

/*
 * Initial conditions.
 */
const double a = 1;
const double psi1 = 1;
const double sigma1 = -2;
const double kappa1 = 0.6;
const double b = 1.3;
const double psi2 = 1;
const double sigma2 = 0;
const double kappa2 = 1;

double f(double x) {
    return 2 * x * x;
}

double p(double x) {
    return 0.5;
}

double q(double x) {
    return -3; //::TODO missing sign
}