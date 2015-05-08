//accepted
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t, i = 0, digit, b_len;
    unsigned long int a, tmp, divisor, number;
    char b[300], dig[2];
    scanf ("%d", &t);
    while (t--)
    {
        number = 0, i = 0;
        scanf ("%ld %s", &a, b);
        b_len = strlen (b);
        if (a == 0)	//handling for zero value
            printf ("%s\n", b);

        else
        {   //if a!=0
            divisor = a;
            while (b_len--)
            {
                strncpy (dig, b + i, 1);
                digit = atoi (dig);
                number = (number * 10 + digit) % divisor;
                i++;
            }
            while (number != 0)
            {
                tmp = number;
                number = divisor;
                divisor = tmp;
                number = number % divisor;
            }
            printf ("%ld\n", divisor);
        }
    }
    return 0;
}
