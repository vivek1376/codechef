/* AC
   needed 64 bit variable, so used
   long long int */

#include <cstdio>
#include <algorithm>

#define MODBASE 1000000007

using namespace std;

int main()
{
    long long int T,N,i,setDiff=0,twoPower=1;
    long int S[100002];
    
    /* no. of test cases */
    scanf("%lld",&T);
    
    while(T--)
    {
	twoPower=1,setDiff=0;

	/* total no. of elements in S' */
	scanf("%lld",&N);

	for(i=0;i<N;i++)
	    scanf("%lld",&S[i]);
	
	sort(S,S+N);

	for(i=0;i<N;i++)
	{
	    setDiff+=((S[i]*twoPower-S[N-1-i]*twoPower)%MODBASE);
	    setDiff%=MODBASE;

	    twoPower=(twoPower*2)%MODBASE;
	    
	    if (setDiff<0) setDiff += MODBASE;
	}
	
	printf("%lld\n",setDiff);
    }

    return 0;
}
