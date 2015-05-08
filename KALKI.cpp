/* vivek < vivek.1376[@]gmail.com > */
/* NP hard */
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct d{
    int a,b;
    float distance;
}pairDistance;

pairDistance pairs[90000];		/* store distance of every pair of points */
int leader[410], rank[410]={0};

void initLeaderArray();
int find(int);
void unionSet (int, int);
bool compareDistance(const pairDistance&,const pairDistance&);

int main()
{
    int T,N,X[410],Y[410],i,j,k,c,edgeCount,p1,p2;

    scanf("%d",&T);
    while(T--)
    {
	scanf("%d",&N);

	/* total no of pairs of points  */
	c=(N*(N-1))/2;

	for(i=1;i<=N;i++)
	    scanf("%d %d",&X[i],&Y[i]);

	/* calculate distance for every pair */
	k=0;
	for(i=1;i<=N;i++)
	    for(j=i+1;j<=N;j++)
	    {
		pairs[k].a=i;
		pairs[k].b=j;
		pairs[k].distance=sqrt((X[i]-X[j])*(X[i]-X[j])+
				       (Y[i]-Y[j])*(Y[i]-Y[j]));
		k++;
	    }

	/* sort distances */
	sort(pairs, pairs+c, compareDistance);

//	for(i=0;i<c;i++)
//	    cout<<pairs[i].a<<" "<<pairs[i].b<<" "<<pairs[i].distance<<endl;

	edgeCount=0,i=0;	/* i stores index of next pair 
				   to be processed */
	initLeaderArray();

	while(edgeCount < N-1)
	{
	    p1=pairs[i].a, p2=pairs[i].b;

	    /* check if pair isn't contained in the same set */
	    if(find(p1)!=find(p2))
	    {
		/* a new edge added, increment count */
		edgeCount++;

		/* coombine sets */
		unionSet(p1,p2);

		/* prints the pair of points */
		printf("%d %d\n",p1,p2);
	    }
	    
	    /* will process the next largest pair */
	    i++;
	}
    }
    return 0;
}
void initLeaderArray()
{
    int i;

    for(i=1;i<=400;i++)
	leader[i]=i;
}

int find(int i)
{
    while(leader[i]!=i)
	i=leader[i];

    return i;
}

void unionSet(int i, int j)
{
    int iLeader=find(i);
    int jLeader=find(j);

    if(rank[iLeader] < rank[jLeader])
	leader[iLeader]=jLeader;

    else if (rank[jLeader] < rank[iLeader])
	leader[jLeader]=iLeader;

    else
    {
	leader[iLeader]=jLeader;
	rank[jLeader]++;
    }
}

bool compareDistance(const pairDistance &p1, const pairDistance &p2)
{
    return (p1.distance < p2.distance);
}
