#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(0));  // change the seed each time?
    
    int lower = 0;
    int upper = 20;
    int random = (rand() % (upper - lower + 1) + lower);
    
    printf("Random: %d", random);
    
    return 0;
}