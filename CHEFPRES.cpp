/* vivek < vivek.1376(at)gmail.com > */
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>

#define SIZE 10001

using namespace std;

vector<int> graph[SIZE];
int product[SIZE]={0};
int parent[SIZE]={0};
int minSubtree[SIZE][102]={{-1}};
int minCity[SIZE][102]={{0}};
int root,k;

void graphDFS (int r);
void graphDFS2();
void setMinSubtree (int city);

int main()
{
    int N, K, B, i, m, n, x, y, Nq;
    scanf("%d %d",&N,&K);
    scanf("%d",&B);

    k=K; 			/* no. of products */

    for(i=0;i<N-1;i++)
    {
	scanf("%d %d",&x,&y);
	graph[x].push_back(y);
	graph[y].push_back(x);
    }

    /* store list of cities for each product */
    for (i = 1; i <= N; i++)
    {
	scanf("%d",&m);
	product[i]=m;
    }

    graphDFS (B);		/* DFS from capital */
    cout << minSubtree[4][1];
    return 0;
    graphDFS2();		/* 2nd DFS */

//    cin >> Nq;			/* no of queries */
    scanf("%d",&Nq);

    for(i=0; i<Nq; i++)
    {
	scanf("%d %d",&m,&n);
	//cin >> m >> n;
	printf("%d\n",minCity[m][n]);
    }
}

void graphDFS (int r)
{
    root=r;

    /* clear visited array first */
//    initVisited();
    int visited[SIZE]={0};

    int w,i;

    /* S will hold list of unexplored nodes */
    stack <int> S;

    /* mark root visited*/
    visited[root]=1;
    parent[root] = root;    /* origin */
    setMinSubtree(root);

    /* push root node onto stack */
    S.push(root);

    int child;
    while (!S.empty())
    {
        w = S.top();
        S.pop();
	
	for(i=0; i<graph[w].size(); i++)
	{
	    child=graph[w][i];
	    if(!visited[child])
	    {
		visited[child]=1;
		parent[child]=w;
		setMinSubtree(child);
		S.push(child);
	    }
	}
    }
}

void setMinSubtree (int city)
{
    int pr=product[city];
    int tempCity=city;

    /* update all the parent cities if 'city' is smaller than the
       parent cities' minSubtree value (for 'product') */
    while (tempCity!=root)
    {
	/* check if the parent node has a minSubtree value for 'product' */
	
	if((minSubtree[tempCity][pr]==-1) ||
	   minSubtree[tempCity][pr]>city)
	    minSubtree[tempCity][pr]=city;

	    tempCity=parent[tempCity];
/*	if ((getMinSubtree(tempCity, product) == -1) ||
	    (getMinSubtree(tempCity, product) > city))
	    minSubtree[tempCity-1][product]=city;
        
	    tempCity=getParent(tempCity);*/
    }
    
    /* for root */
    if((minSubtree[tempCity][pr]==-1) ||
       minSubtree[tempCity][pr]>city)
	tempCity=parent[tempCity];
}

void graphDFS2()
{
    int i, w, minS;

    /* clear visited array */
    int visited[SIZE]={0};

    stack <int> S;      /* S will hold list of unexplored nodes */

    visited[root]=1;

    S.push(root);

    /* for root */
    for(i=1; i<=k; i++)
	minCity[root][i]=minSubtree[root][i];
//	setMinCity(root,i,getMinSubtree(root,i));
    
    int child;
    while (!S.empty())
    {
	w=S.top();
	S.pop();

	for(i=0; i<graph[w].size(); i++)
	{
	    child=graph[w][i];
	    if(!visited[child])
	    {
		visited[child]=1;
		S.push(child);
		
		for(i=1; i<=k; i++)
		{
		    minS=minSubtree[child][i];
		    (minS!=-1)?minCity[child][i]=minS:
			minCity[child][i]=
			minSubtree[parent[child]][i];
		}
	    }
	}
    }
}
