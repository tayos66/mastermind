#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    const int n = 6;

    int x[n];
    int guess[n];
    int count = 0;
    int black = 0;
    int white = 0;

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        x[i] = (rand() * 6L) / RAND_MAX + 1;
    }

    do
    {
        int input;

        count++;

        scanf("%u", &input);

        for (int i = n - 1; i >= 0; i--)
        {
            guess[i] = input % 10;
            input /= 10;
        }

        black = 0;
        white = 0;

        for (int i = 0; i < n; i++)
        {
            if (guess[i] == x[i])
            {
                black++;
                guess[i] = 0; // "verbrauchen"
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (guess[j] == x[i])
                    {
                        white++;
                        break;
                    }
                }
            }
        }

        printf("%d black, %d white\n", black, white);
    } while (black != n);

    printf("%d %s\n", count, count > 1 ? "guesses" : "guess");
}
