//wrong answer
#include <stdio.h>

int main()
{
	unsigned long int t,ans,n,c1;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		ans=1;		//agency 1 connects all points
		for(c1=2;c1<n;c1++)
		{
			if(c1<=n/2)
			{
				if(n%c1!=0)
					ans++;
			}
			else
			{
				if(n%(n-c1)!=0)
					ans++;
					
				if(c1==n-1)
					ans++;
			}
			
		}
		printf("%ld\n",ans);
	}
	return 0;
}
