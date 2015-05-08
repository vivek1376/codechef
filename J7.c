/*
 * codechef easy >> The Best Box
 * 
*/

#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int test_cases,p,s;
	float d1,d2,l1,l2,vol1,vol2;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%d %d",&p,&s);
		d1=((float)p+sqrt(pow((float)p,2.0)-24.0*(float)s))/12.0;		
		d2=((float)p-sqrt(pow((float)p,2.0)-24.0*(float)s))/12.0;
		l1=((float)p-8.0*d1)/4.0;
		l2=((float)p-8.0*d2)/4.0;
		vol1=d1*d1*l1;
		vol2=d2*d2*l2;
		if(vol1>vol2)
			printf("%.2f\n",vol1);
		else
			printf("%.2f\n",vol2);		
	}
	return 0;
}
