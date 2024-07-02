#include <stdio.h>

// Function prototype (declaration)
int square(int n);

int main(void)
{
    // Print the squares of integers from 1 - 10
    for (unsigned int i = 0; i < 10; i++)
    {
        printf("%d ", square(i+1));
    }
    puts("");
    return 0;
}

// Function definition - returns the square of a number n
int square(int n)
{
    return n * n;
}