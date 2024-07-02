#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // Ask the user for a seed
    unsigned int seed;
    
    printf("%s", "Randomized dice simulation.\n");
    printf("%s", "> Enter a seed: ");
    scanf("%u", &seed);

    // Randomize the generated sequence
    srand(seed);

    for (unsigned int i = 0; i < 20; i++)
    {
        // Start a new line after every 5th iteration
        if (i % 5 == 0)
            printf("\nIteration %d: ", (i / 5) + 1);

        // Picks a random number from 1 - 6
        int random = 1 + (rand() % 6);
        printf("%4d ", random);
    }

    return 0;
}