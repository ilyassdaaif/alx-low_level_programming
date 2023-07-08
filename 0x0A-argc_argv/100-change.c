#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins
 * to make change for an amount of money.
 * @argc: number of command line arguments.
 * @argv: pointer to an array of command line arguments.
 * Return: 0-success, non-zero-fail.
 */
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i, coinCount = 0, money = atoi(argv[1]);
        int cents[] = {25, 10, 5, 2, 1};
        int numCoins = sizeof(cents) / sizeof(cents[0]);

        if (money == 0)
        {
            printf("0\n");
            return 0;
        }

        for (i = 0; i < numCoins; i++)
        {
            if (money >= cents[i])
            {
                coinCount += money / cents[i];
                money = money % cents[i];
                if (money % cents[i] == 0)
                {
                    break;
                }
            }
        }
        printf("%d\n", coinCount);
    }
    else
    {
        printf("Error\n");
        return 1;
    }
    return 0;
}
