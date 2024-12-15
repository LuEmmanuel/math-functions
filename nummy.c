#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define EPSILON 1e-14 // Define a small threshold for floating-point comparisons

// Display the usage instructions and exit the program
void usage(void) {
    printf("Usage:  ./nummy -e N\n");
    printf("        ./nummy -l N\n");
    printf("        ./nummy -p N\n");
    printf("        ./nummy -s N\n");
    printf("        for integer N\n");
    exit(1);
}

// Compute the absolute value of a given double
// Parameters:
// - x: The number for which to compute the absolute value
// Returns: The absolute value of x
double absolute_value(double x) {
    if (x < 0) return (x * -1); // If x is negative, return its positive counterpart
    return x; // Otherwise, return x as is
}

// Compute the square root of a non-negative number using the Newton-Raphson method
// Parameters:
// - x: The number for which to compute the square root
// Returns: The square root of x
double my_sqrt(double x) {
    double next_y = 1.0; // Initial guess for sqrt(x)
    double y = 0.0; // Variable to store the previous guess

    // Handle invalid input (negative numbers)
    if (x < 0) {
        printf("Enter a positive integer for sqrt\n");
        usage();
    }

    // Iterate until the difference between guesses is within EPSILON
    while (absolute_value(next_y - y) > EPSILON) {
        y = next_y;
        next_y = 0.5 * (y + x / y); // Update the guess using the Newton-Raphson formula
    }
    return next_y;
}

// Approximate the value of e (Euler's number) using a series expansion
// Parameters:
// - n: The number of terms to include in the series
// Returns: The approximate value of e
double my_e(int n) {
    double sum = 0.0;
    double factorial = 1.0; // Start with 1 since 0! = 1

    // Compute the summation of the series
    for (int k = 0; k <= n - 1; ++k) {
        if (k == 0) factorial = 1; // Handle 0! explicitly
        else factorial *= k; // Update factorial for each term
        sum += 1.0 / factorial; // Add the current term to the sum
    }
    return sum;
}

// Approximate the value of pi using the Gregory-Leibniz series
// Parameters:
// - n: The number of terms to include in the series
// Returns: The approximate value of pi
double my_pi(int n) {
    double pi = 0.0;
    double threeRaisedToK = 1.0;

    // Compute the summation of the series
    for (int k = 0; k <= n - 1; ++k) {
        if (k == 0) threeRaisedToK = 1; // Handle (-3)^0 explicitly
        else threeRaisedToK *= -3; // Update (-3)^k for each term
        pi += 1.0 / (threeRaisedToK * (2 * k + 1)); // Add the current term to the sum
    }
    return pi * my_sqrt(12); // Multiply by sqrt(12) to approximate pi
}

// Approximate the natural logarithm of 2 (ln(2)) using a series expansion
// Parameters:
// - n: The number of terms to include in the series
// Returns: The approximate value of ln(2)
double my_ln2(int n) {
    double ln = 0.0;
    double twoRaisedToK = 1.0;

    // Compute the summation of the series
    for (int k = 1; k <= n; ++k) {
        twoRaisedToK *= 2; // Update 2^k for each term
        ln += 1.0 / (twoRaisedToK * k); // Add the current term to the sum
    }
    return ln;
}

/*
 * Main function to parse arguments and call the appropriate mathematical function
 * Example usage: ./nummy -p 10
 * Parameters:
 * - argc: The number of arguments passed to the program
 * - argv: The array of arguments
 * Returns: 0 on success
 */
int main(int argc, char **argv) {
    if (argc != 3) { // If the argument count is not 3, display usage error
        usage();
    }

    int n = atoi(argv[2]); // Convert the second argument to an integer

    // Compare the first argument and call the corresponding function
    if (strcmp(argv[1], "-e") == 0) {
        printf("With %d terms, e is approximately %.13f\n", n, my_e(n));
    } else if (strcmp(argv[1], "-l") == 0) {
        printf("Given %d terms, ln(2) is %.13f\n", n, my_ln2(n));
    } else if (strcmp(argv[1], "-p") == 0) {
        printf("With %d terms, pi is approximately %.13f\n", n, my_pi(n));
    } else if (strcmp(argv[1], "-s") == 0) {
        printf("Square root of %d is approximately %.13f\n", n, my_sqrt(n));
    } else {
        usage();
    }

    return 0;
}
~                                                                                                                                                                                                                                           
~                                                              
