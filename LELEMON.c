//accepted
//august 2013 challenge
#include <stdio.h>
#include <string.h>

void quickSort (unsigned int unsorted[], int start, int end_pos);

int main()
{
    int T, N, C[110], P[10010];
    unsigned int M, V[101][10001], i, j, litres;

    scanf ("%d", &T);

    while (T--)
    {
        scanf ("%d %d", &N, &M);

        for (i = 0; i < M; i++)
            scanf ("%d", &P[i]);

        for (i = 0; i < N; i++)
        {
            scanf ("%d", &C[i]);

            for (j = 0; j < C[i]; j++)
                scanf ("%d", &V[i][j]);

            quickSort (V[i], 0, C[i] - 1);
        }

        for (i = 0, litres = 0; i < M; i++)
        {
            if (C[P[i]] > 0)       //check if bottles finished
            {
                --C[P[i]];      //C is bottle no.
                litres += V[P[i]][C[P[i]]];
            }
        }

        printf ("%d\n", litres);
    }

    return 0;
}


void quickSort (unsigned int unsorted[], int start, int end)
{
    long int arr_len, i, j;
    unsigned long int pivot, temp, mid;
    arr_len = end - start + 1;

    //base case
    if (arr_len < 2)
        return;

    else
    {
        //median pivot

        mid = (start + end) / 2;

        if ( (unsorted[mid] >= unsorted[start] && unsorted[mid] <= unsorted[end]) ||
                (unsorted[mid] <= unsorted[start] && unsorted[mid] >= unsorted[end]))
        {
            temp = unsorted[mid];
            unsorted[mid] = unsorted[start];
            unsorted[start] = temp;
        }
        else if ( (unsorted[end] >= unsorted[start] && unsorted[end] <= unsorted[mid]) ||
                  (unsorted[end] <= unsorted[start] && unsorted[end] >= unsorted[mid]))
        {
            temp = unsorted[end];
            unsorted[end] = unsorted[start];
            unsorted[start] = temp;
        }

        pivot = unsorted[0 + start];    //why?

        for (i = start + 1, j = start + 1; j < start + arr_len; j++)
        {
            if (unsorted[j] <= pivot)
            {
                temp = unsorted[j];
                unsorted[j] = unsorted[i];
                unsorted[i] = temp;
                i++;
            }
        }

        temp = unsorted[i - 1];
        unsorted[i - 1] = unsorted[0 + start];
        unsorted[0 + start] = temp;
    }

    quickSort (unsorted, 0 + start, i - 2);
    quickSort (unsorted, i, end);
}

