//#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

void findFactors(unsigned long long int);
vector <unsigned long long int> primeFactors;

int main()
{
//    cout<<sizeof(unsigned long long int);//d
    unsigned long long int T,A,B;
    char flag=0;
    scanf("%llu",&T);

    while(T--)
    {
	scanf("%llu %llu",&A,&B);
	
	primeFactors.clear();
	findFactors(B);

	flag=0;
	for(vector<unsigned long long int>::iterator it=primeFactors.begin();
	    it!=primeFactors.end();++it)
	    if(A%(*it)!=0)
	    {
		flag=1;
		break;
	    }

	if (flag==1)
	    printf("No\n");
	else
	    printf("Yes\n");
    }

    return 0;
}

void findFactors(unsigned long long int num)
{
    unsigned long long int i=2, nRoot=sqrt(num)+1, lastFactor=0;
    
    while(i<nRoot)
    {
	while(num%i==0)
	{
	    num=num/i;
	    if(i!=lastFactor)
	    {
		primeFactors.push_back(i);
		lastFactor=i;
	    }
	}

	i==2?(++i):i+=2;
    }
}
