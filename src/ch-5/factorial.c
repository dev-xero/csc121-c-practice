#include <stdio.h>

// Prototype for factorial function
// Since it'll return fairly large outputs
unsigned long long int factorial(unsigned int n);

/**
 * Factorial function example.
 * A factorial, depicted by n! is defined by:
 *  n * (n-1) * (n-2) *...* 1
 */
int main(void)
{
    // Get the number to compute factorials up to
    unsigned int max;
    printf("%s", "> Calculate factorials up to: ");
    scanf("%u", &max);

    for (unsigned int i = 0; i <= max; i++)
        // Interesting, use "-" before the number to left align
        printf("- %3u! = %-20llu\n", i, factorial(i));

    return 0;
}

// Function definition for factorial proto
unsigned long long int factorial(unsigned int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}
