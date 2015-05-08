#include <stdio.h>

int main()
{
    unsigned long int n;
    unsigned int t,g,i,q;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&g);	//no. of games
	while(g--)
	{
	    scanf("%d %ld %d",&i,&n,&q);
	    if(n%2==0)
	    {
		printf("%ld\n",n/2);
	    }
	    else
	    {
		if(i==q)
		    printf("%ld\n",n/2);
		else
		    printf("%ld\n",n/2+1);
	    }
	}
    }
    return 0;
}
