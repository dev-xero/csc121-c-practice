#include <stdio.h>

// Function prototype
int maximum(int a, int b, int c);

int main(void)
{
    int a; int b; int c;
    printf("> Maximum of three numbers.\n");
    printf("> Enter three integers: a, b, c: ");

    scanf("%d, %d, %d", &a, &b, &c);
    printf("> Max is: %d", maximum(a, b, c));

    return 0;
}

// Returns the maximum of three integers
int maximum(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    
    if (b > a && b > c)
        return b;
    
    return c;
}

