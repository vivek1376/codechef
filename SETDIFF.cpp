//#include <iostream>
#include <cstdio>
#include <algorithm>

#define MODBASE 1000000007

using namespace std;

int main()
{
    long int T,N,i,S[100002],setDiff=0,twoPower=1;
/*    int ee=-7;
    ee%=5;
    printf("%d\n",ee);*/
    //  return 0;
    scanf("%ld",&T);
    
    while(T--)
    {
	twoPower=1,setDiff=0;

	scanf("%ld",&N);

	for(i=0;i<N;i++)
	    scanf("%ld",&S[i]);
	
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
	    
	printf("%ld\n",setDiff);
//	fflush(stdin);//d
    }

    return 0;
}
