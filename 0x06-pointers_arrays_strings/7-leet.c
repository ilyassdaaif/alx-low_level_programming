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
	int value[] = {4, 3, 0, 7, 1};
	unsigned int i;

	while (*c)
	{
		for (i = 0; i < sizeof(key) / sizeof(char); i++)
		{
			/*32 is the difference between lower case letters and apper case letters*/
			if (*c == key[i] || *c == key[i] + 32)
			{
								
