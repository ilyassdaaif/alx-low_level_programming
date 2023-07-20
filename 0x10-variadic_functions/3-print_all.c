#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0;
    char c;
    char *str;
    float f;

    va_start(args, format);

    while (format && format[i])
    {
        c = format[i];

        if (i != 0)
        {
            switch (c)
            {
                case 'c':
                    printf(", ");
                    break;
                case 'i':
                    printf(", ");
                    break;
                case 'f':
                    printf(", ");
                    break;
                case 's':
                    printf(", ");
                    break;
                default:
                    break;
            }
        }

        if (c == 'c')
        {
            putchar(va_arg(args, int));
        }
        else if (c == 'i')
        {
            printf("%d", va_arg(args, int));
        }
        else if (c == 'f')
        {
            printf("%f", va_arg(args, double));
        }
        else if (c == 's')
        {
            str = va_arg(args, char*);
            if (str == NULL)
                printf("(nil)");
            else
                printf("%s", str);
        }

        i++;
    }

    va_end(args);
    printf("\n");
}
