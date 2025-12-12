#include <stdio.h>
#include <math.h>

// Function definition: f(x) = x^2 - 2
double f(double x) {
    return x*x - 2;
}

// Derivative: f'(x) = 2x
double f_prime(double x) {
    return 2*x;
}

int main() {
    double x0 = 1.0;   // Initial guess
    double tol = 1e-6; // Tolerance
    int max_iter = 100;
    int iter = 0;

    while (iter < max_iter) {
        double x1 = x0 - f(x0)/f_prime(x0); // Newton-Raphson formula
        printf("Iteration %d: x = %.6f\n", iter+1, x1);

        if (fabs(x1 - x0) < tol) {
            printf("Root found: %.6f\n", x1);
            break;
        }
        x0 = x1;
        iter++;
    }

    if (iter == max_iter) {
        printf("Method did not converge within %d iterations.\n", max_iter);
    }

    return 0;
}

