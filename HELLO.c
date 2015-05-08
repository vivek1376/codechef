//august 2013  challenge
//accepted

#include <stdio.h>

int main()
{
    int T, N, plans, M, C, best_plan;
    unsigned long int U;
    float R, D, cost_diff, best_cost_diff;

    scanf ("%d", &T);
    while (T--)
    {
        best_plan = 0;
        scanf ("%f %lu %d", &D, &U, &N);
        plans = N;
        
        best_cost_diff=0.0;
        while (N--)
        {
            scanf ("%d %f %d", &M, &R, &C);
            cost_diff = (U * D) - ( ( ( (float) U * (float) M * R) + (float) C) / (float) M);
            if (cost_diff > best_cost_diff)
            {
                best_plan = plans - N;
                best_cost_diff = cost_diff;
            }
        }
        printf ("%d\n", best_plan);
    }


    return 0;
}
