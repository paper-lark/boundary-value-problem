#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Exports.
 */
extern const double a;
extern const double psi1;
extern const double sigma1;
extern const double kappa1;
extern const double b;
extern const double psi2;
extern const double sigma2;
extern const double kappa2;

extern double f(double x);
extern double p(double x);
extern double q(double x);

/*
 * Statics.
 */
static double h = 0;
static unsigned n = 0;

/**
 * Function prints formatted function table for standalone equation. 
 */
void print(const double *y, unsigned n) {
    printf("       x        |        y       \n");
    printf("---------------------------------\n");
    double x = a - h / 2;
    for (unsigned i = 0; i <= n; i++) {
        printf("%15.8g | %15.8g\n", x, y[i]);
        x += h;
    }
    printf("\n");
}

/*
 * Functions assist in calculating indexed values.
 */

double x_i(unsigned i) {
    return a - h / 2 + h * i;
}

double p_i(unsigned i) {
    return p(x_i(i));
}

double q_i(unsigned i) {
    return q(x_i(i));
}

double f_i(unsigned i) {
    if (i == n) {
        return kappa2;
    } else if (i == 0) {
        return kappa1;
    } else {
        return f(x_i(i));
    }
}

double A(unsigned i) {
    if (i == n) {
        return psi2 / 2 - sigma2 / h;
    } else {
        return (2 - p_i(i) * h) / (2 * h * h);
    }
}

double B(unsigned i) {
    if (i == 0) {
        return psi1 / 2 + sigma1 / h;
    } else {
        return (2 + p_i(i) * h) / (2 * h * h);
    }
}

double C(unsigned i) {
    if (i == 0) {
        return psi1 / 2 - sigma1 / h;
    } else if (i == n) {
        return psi2 / 2 + sigma2 / h;
    } else {
        return q_i(i) - 2 / (h * h);
    }
}

/*
 * Entry point.
 */
int main(void) {
    /*
     * Get number of points.
     */
    printf("Enter number of points:\n");
    scanf("%u", &n);
    h = (b - a) / (n - 1);

    /*
     * Allocate memory for coefficients and the result.
     */
    double *alpha = calloc(n + 1, sizeof(alpha[0]));
    double *beta = calloc(n + 1, sizeof(beta[0]));
    double *y = calloc(n + 1, sizeof(y[0]));
    if (y == NULL || beta == NULL || alpha == NULL) {
        fprintf(stderr, "> error: failed to allocate memory\n");
        free(alpha);
        free(beta);
        free(y);
        exit(2);
    }

    /*
     * Calculate coefficients.
     */
    alpha[0] = -B(0) / C(0);
    beta[0] = f_i(0) / C(0);
    for (unsigned i = 1; i < n; i++) {
        double denominator = C(i) + alpha[i - 1] * A(i);
        alpha[i] = -B(i) / denominator;
        beta[i] = (f_i(i) - A(i) * beta[i - 1]) / denominator;
    }

    /*
     * Reverse traversal.
     */
    y[n] = (f_i(n) - A(n) * beta[n - 1]) / (C(n) + alpha[n - 1] * A(n));
    for (unsigned i = n - 1; i < n; i--) {
        y[i] = alpha[i] * y[i + 1] + beta[i];
    }

    /*
     * Print the result.
     */
    print(y, n);

    /*
     * Free resources.
     */
    free(alpha);
    free(beta);
    free(y);
}