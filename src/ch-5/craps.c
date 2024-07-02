#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Game state
enum GameState
{
    CONTINUE,
    WON,
    LOST
};

// Function prototype for rolling a dice
unsigned int
rollDice();

/**
 * Simulates a simple game of "craps!"
 *
 * The Rules:
 *  1. If the player rolls a sum of 7 or 11 on the first try,
 *     then they win.
 *  2. If they roll a 2, 3 or 12 on the first try, then they
 *     lose.
 *  3. Otherwise, keep a track of their sum, "point", then allow
 *     then to keep rolling until they score their point.
 *  4. If the player rolls a 7 before reaching their point after
 *     the first roll, then they lose.
 */
int main(void)
{
    printf("- CRAPS! GAME SIMULATION.\n");
    // Randomize the seed
    srand(time(NULL));

    // Game state and variables
    unsigned int myPoint = 0;
    unsigned int rolledSum = rollDice();
    enum GameState state;

    // Determine how the game will play out
    switch (rolledSum)
    {
    case 7:
    case 11:
        printf("- Player wins! Rolled a %u!\n", rolledSum);
        state = WON;
        break;

    case 2:
    case 3:
    case 12:
        printf("- Player loses! Rolled a %u!\n", rolledSum);
        state = LOST;
        break;

    default:
        myPoint = rolledSum;
        state = CONTINUE;
        printf("- Game shall continue, point is: %u\n", rolledSum);
        break;
    }

    // Keep rolling until player reaches their point
    if (state == CONTINUE)
    {
        while (1)
        {
            rolledSum = rollDice();
            if (rolledSum == myPoint)
            {
                printf("- Player wins! Rolled a %u\n", rolledSum);
                state = WON;
                break;
            }
            else if (rolledSum == 7)
            {
                printf("- Player loses! Rolled a %u\n", rolledSum);
                state = LOST;
                break;
            }
        }
    }

    return 0;
}

/**
 * Function definition for rollDice()
 * Returns the sum of two randomly rolled dies.
 */
unsigned int rollDice()
{
    unsigned int die1 = 1 + (rand() % 6);
    unsigned int die2 = 1 + (rand() % 6);
    unsigned int sum = die1 + die2;

    printf("- Player rolled %u + %u = %u\n", die1, die2, sum);
    return sum;
}