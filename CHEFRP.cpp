/* AC */
#include <cstdio>

using namespace std;

int main()
{
    unsigned int T,N,A[100001],i, minIngd=10000, total=0;
    char ifInvalid=0;

    scanf("%u",&T);
    
    while(T--)
    {
	minIngd=10000,total=0,ifInvalid=0;

	scanf("%u",&N);

	for(i=0;i<N;i++)
	    scanf("%u",&A[i]);
	
	for(i=0;i<N;i++)
	{
	    if(A[i]<2)
	    {
		printf("-1\n");
		ifInvalid=1;
		break;
	    }

	    if(A[i]<minIngd)
		minIngd=A[i];

	    total+=A[i];
	}

	if(!ifInvalid)
	    printf("%u\n",total-minIngd+2);
    }

    return 0;
}

	    
	    
	    
