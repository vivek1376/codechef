//AC: viewed editorial

#include <cstdio>
#include <vector>
#include <cmath>

typedef unsigned long long int ullong;

using namespace std;

bool ifUniqueFactor(ullong a, ullong b);
ullong findHCF(ullong a, ullong b);
    
int main()
{
    unsigned long long int T,A,B;
//    printf("%lld\n",findHCF(100,1));
    //  return 0;
    char flag=0;

    scanf("%llu",&T);

    while(T--)
    {
	scanf("%llu %llu",&A,&B);
	
	if(!ifUniqueFactor(A,B))
	    printf("Yes\n");
	else
	    printf("No\n");
    }

    return 0;
}

ullong findHCF(ullong a, ullong b)
{
    ullong c;

    while(c=a%b, c)
    {
	a=b;
	b=c;
    }

    return b;
}

bool ifUniqueFactor(ullong a, ullong b)
{
    if (b==1)
	return false;

    ullong h;

    h=findHCF(a,b);

    if(h==1)
	return true;
    else
	ifUniqueFactor(a,b/h);
}
