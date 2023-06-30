#include "main.h"

/**
 * leet - encodes a string into 1337
 * @c: String
 * Return: string that is encoded
*/

char *leet(char *c)
{
        char *cp = c;
        char Key[] = {'A', 'E', 'O', 'T', 'L'};
        int Value[] = {4, 3, 0, 7, 1};
        unsigned int i;

        while (*c)
        {
                for (i = 0; i < sizeof(Key) / sizeof(char); i++)
                {
                        /* 32 is the difference between lowercase letters and uppercase letters */
                        if (*c == Key[i] || *c == Key[i] + 32)
                        {
                                *c = '0' + Value[i];
                        }
                }
                c++;
        }

        return cp;
}
