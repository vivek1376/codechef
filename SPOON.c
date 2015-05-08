//spoon in the matrix
//accepted
#include <stdio.h>
#include <ctype.h>

int main()
{
    int spoon, t, r, c, i, j;
    char matrix[100][100], line[101];

    scanf ("%d", &t);
    while (t--)
    {
        spoon = 0;
        scanf ("%d %d", &r, &c);

        //fill matrix
        for (i = 0; i < r; i++)
        {
            scanf ("%s", line);
            for (j = 0; j < c; j++)
                matrix[i][j] = tolower (line[j]);
        }

        //now check
        for (i = 0; i < r; i++)
        {
            for (j = 0; j <= c - 5; j++)
                if (matrix[i][j] == 's' && matrix[i][j + 1] == 'p' && matrix[i][j + 2] == 'o' && matrix[i][j + 3] == 'o' && matrix[i][j + 4] == 'n')
                {
                    spoon = 1;
                    break;
                }

            if (spoon == 1)
                break;
        }

        for (i = 0; i <= r - 5; i++)
        {
            for (j = 0; j < c; j++)
                if (matrix[i][j] == 's' && matrix[i + 1][j] == 'p' && matrix[i + 2][j] == 'o' && matrix[i + 3][j] == 'o' && matrix[i + 4][j] == 'n')
                {
                    spoon = 1;
                    break;
                }

            if (spoon == 1)
                break;
        }

        if (spoon == 1)
            printf ("There is a spoon!\n");
        else
            printf ("There is indeed no spoon!\n");
    }
    return 0;
}
