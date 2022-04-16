#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{

    srand(time(NULL));

    int x = (rand() * 100L) / RAND_MAX + 1;

    int guess;

    do
    {
        scanf("%u", &guess);
        /* printf("x = %u\nguess = %u\n", x, guess); */

        if (guess < x)
        {
            printf("Too small\n");
        }

        if (guess > x)
        {
            printf("Too big\n");
        }

        if (guess == x)
        {
            printf("You got it!\n");
        }
    } while (guess != x);
}