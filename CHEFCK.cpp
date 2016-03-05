#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned long int N, Q, K, a, b, c, d, e, f, r, s,
	t, m, x, L1, D1, Lm, Dm, Da, Dc, La, Lc, i, j, k;

    unsigned long long int *A = (unsigned long long int *)
                                malloc (10000010 * sizeof (unsigned long long int)),
                                temp1, temp2, temp3, tPow;

    scanf ("%ld %ld %ld", &N, &K, &Q);

    scanf ("%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %lld",
           &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &A[1]);

    scanf ("%ld %ld %ld %ld %ld",
           &L1, &La, &Lc, &Lm, &D1, &Da, &Dc, &Dm);

    tPow = t;
    for (i = 2; i <= N; i++)
    {
        tPow = (tPow * t) % s;

        if (tPow <= r)
        {
            temp1 = (A[i - 1] * A[i - 1]) % m;
            temp2 = (a * temp1) % m;

            A[i] = temp2;

            temp1 = (b * A[i - 1]) % m;
            temp1 = (temp1 + c) % m;

            A[i] = (A[i] + temp1) % m;
        }
        else
        {
            temp1 = (A[i - 1] * A[i - 1]) % m;
            temp2 = (d * temp1) % m;

            A[i] = temp2;

            temp1 = (e * A[i - 1]) % m;
            temp1 = (temp1 + f) % m;

            A[i] = (A[i] + temp1) % m;

        }

	for(i=1; i<=Q; i++)
	{
	    temp1=(La*L1)%Lm;
	    temp1=(temp1+Lc)%Lm;
	    L1=temp1;

	    temp1=(Da*D1)%Dm;
	    temp1=(temp1+Dc)%Dm;
	    D1=temp1;
	    L=L1+1;
	    R=min(L+K-1+D1, N);
	}
    }

    return 0;
}
