//#include <iostream>
#include <cstdio>
#include <algorithm>

#define MODBASE 1000000007

using namespace std;

int main()
{
    //cout<<-1%3<<endl;//d
    long int T,N,i,S[100002],setDiff=0,twoPower=1;
    //  int ee=1000000011;
    //ee%=MODBASE;
//    printf("%d",ee);
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

	setDiff=(S[0]-S[N-1])%MODBASE;
	(setDiff<0)?(setDiff+=MODBASE):setDiff;

	for(i=1;i<N;i++)
	{
	    twoPower*=2;
	    twoPower%=MODBASE;

	    setDiff+=((S[i]*twoPower-S[N-1-i]*twoPower)%MODBASE);
	    setDiff%=MODBASE;
	    (setDiff<0)?(setDiff+=MODBASE):setDiff;
	}
	printf("%ld\n",setDiff);
	fflush(stdin);
    }

    return 0;
}
