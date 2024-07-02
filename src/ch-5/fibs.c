// Header files
#include <stdio.h>

// Macros
#define CACHE_SIZE 100

// Function prototypes
unsigned long fibCached(unsigned int n, unsigned long cache[100], unsigned int *iters);
unsigned long fib(unsigned int n, unsigned int *iters);

// Entry point for fibonacci sequence generator
int main(void)
{
    unsigned long cache[CACHE_SIZE] = {1, 1, 2, 3, 5}; // arbitrary length
    unsigned int target;

    unsigned int cached_iters = 0;
    unsigned int uncached_iters = 0;

    // Prompt user for target
    printf("> Generate fibonacci numbers up to: ");
    scanf("%d", &target);

    printf("%s", "Cached: ");
    for (unsigned int i = 0; i <= target; i++)
    {
        printf("%lu ", fibCached(i, cache, &cached_iters));
    }

    printf("\n%s", "Uncached: ");
    for (unsigned int i = 0; i <= target; i++)
        printf("%lu ", fib(i, &uncached_iters));

    printf("\nTook: %d recursions (cached)", cached_iters);
    printf("\nTook: %d recursions (uncached)", uncached_iters);

    return 0;
}

// Regular version of Fibonacci algorithm
unsigned long fib(unsigned int n, unsigned int *iters)
{
    *iters += 1;
    if (n == 0 || n == 1)
        return 1;

    return fib((n - 1), iters) + fib((n - 2), iters);
}

// Cached version of the Fibonacci algorithm
unsigned long fibCached(unsigned int n, unsigned long cache[CACHE_SIZE], unsigned int *iters)
{
    *iters += 1;
    if (n == 0 || n == 1)
        return 1;

    if (cache[n] == 0)
    {
        cache[n] = fibCached((n - 1), cache, iters) + fibCached((n - 2), cache, iters);
        return cache[n];
    }
    else
        return cache[n];
}