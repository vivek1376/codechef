//WA
#include <stdio.h>

int main()
{
    int T;
    unsigned long long int N, K;
    scanf ("%d", &T);
    while (T--)
    {
        fflush(stdin);
        scanf ("%lld %lld", &N, &K);
        if (K == 0)
            printf ("0 0\n");
        else
            printf ("%lld %lld\n", (N / K), (N % K));
    }
    return 0;
}
