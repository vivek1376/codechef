/* AC
   needed 64 bit variable, so used
   long long int */

#include <cstdio>
#include <algorithm>

#define MODBASE 1000000007

using namespace std;

int main()
{
/*    printf("size %d\n",sizeof(long long int));
    long long int p,q,r; //d
    p=MODBASE,q=MODBASE;
    r=(p*q)%11;
    printf("%lld\n",r);
*/  
    long long int T,N,i,S[100002],setDiff=0,twoPower=1;
/*    int ee=-7;
    ee%=5;
    printf("%d\n",ee);*/
    //  return 0;

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
//	for(i=0;i<N;i++)
//	    printf(">%ld\n",S[i]);

//	setDiff=(S[0]-S[N-1])%MODBASE;
//	(setDiff<0)?(setDiff+=MODBASE):setDiff;

//	printf("setdiff: %d\n",setDiff);//d

	for(i=0;i<N;i++)
	{
	    setDiff+=((S[i]*twoPower-S[N-1-i]*twoPower)%MODBASE);
	    setDiff%=MODBASE;

	    twoPower=(twoPower*2)%MODBASE;
	    
	    if (setDiff<0) setDiff += MODBASE;
	}
	
//	(setDiff<0)?(setDiff+=MODBASE):setDiff;
//	setDiff%=MODBASE;//d
	    
	printf("%lld\n",setDiff);
//	fflush(stdin);//d
    }

    return 0;
}
