/* vivek < vivek.1376(at)gmail.com > */
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cstdio>
#include <unordered_map>

#define MIN(x,y) ((x)<(y)?(x):(y))

using namespace std;

class Node {
private:
    int val;
    char visited;
    /* map for dfs from each vertex */
public:
    Node();	    
    void setVal (int val);
    int getVal();
    bool ifVisited();
};

class Graph {
private:
    int nodeNum; 		/* no. of nodes */
    int prNum;			/* no. of products */
    int root;			/* root node */
    
    vector <list <Node> > graph;	/* adjacency list representation */
    unordered_map <int ,int> cProduct;    /* map city with product */
    vector <bool> visited;		/* stores explored nodes */
    unordered_map <int, int> parent;    /* stores parent nodes */
    vector <unordered_map <int, int> > minSubtree;    /* store min node in subtree 
							 for a paticular product */
    vector <unordered_map <int, int> > minCity; /* final answer */

public:
    Graph (int nodeNum, int prNum);
    void addEdge (int v, int w);
    void setProduct(int node, int p);
    vector <list <Node> >::reference getElement (int n);
    void initVisited();
    void markVisited (int node);
    bool ifVisited (int node);
    int getParent (int node);
    void printVisited ();
    void DFS (int root);
    void DFS2();
    void initMinCity();
    void initMinSubtree();
    void setMinCity(int city, int pr, int minCity);
    int getMinCity (int city, int pr);
    int getMinSubtree(int city, int pr);
    void setMinSubtree (int n);
};

int main()
{
    int N, K, B, i, m, n, x, y, Nq;
    scanf("%d %d",&N,&K);
//    cin >> N >> K;
    scanf("%d",&B);
//    cin >> B;

    Graph myGraph (N, K);

    i = N - 1;

    while (i--)
    {
	scanf("%d %d",&x,&y);
        //cin >> x >> y;
        myGraph.addEdge (x, y);
    }

    /* store list of cities for each product */
//    unordered_map <int, vector <int> > pCities;
    for (i = 0; i < N; i++)
    {
//        cin >> m;
	scanf("%d",&m);
	myGraph.setProduct(i+1,m);

	/* add city to list for the product */
	//      pCities[m].push_back (i + 1);
    }

    myGraph.DFS (B);		/* DFS from capital */

    myGraph.DFS2();		/* 2nd DFS */

//    cin >> Nq;			/* no of queries */
    scanf("%d",&Nq);

    for(i=0; i<Nq; i++)
    {
	scanf("%d %d",&m,&n);
	//cin >> m >> n;
	printf("%d\n",myGraph.getMinCity(m,n));
	//cout << myGraph.getMinCity(m,n) << endl;
    }
}

Node::Node()
{
    visited = 0;
}

int Graph::getParent (int node)
{
    return parent[node];
}

Graph::Graph (int nodeNum, int prNum)
{
    this->nodeNum = nodeNum;
    this->prNum=prNum;
    graph.resize (nodeNum);
}

void Graph::addEdge (int v, int w)
{
    Node n;

    n.setVal (w);
    getElement (v).push_back (n);

    /* bidirectional edge */
    n.setVal (v);
    getElement (w).push_back (n);
}

vector <list <Node> >::reference Graph::getElement (int n)
{
    return graph[n - 1];
}

void Graph::setMinCity (int city, int pr, int minCity)
{
    this->minCity[city-1][pr]=minCity;
} 

int Graph::getMinCity (int city, int pr)
{
    if (minCity[city-1].find(pr)==minCity[city-1].end())
	return -1;
    else
	return minCity[city-1][pr];
}

void Graph::DFS2()
{
    int i, w, minS;

    /* clear visited array */
    initVisited();

    initMinCity();

    stack <int> S;		/* S will hold list of unexplored nodes */

    markVisited (root);

    S.push(root);

    /* for root */
    for(i=1; i<=prNum; i++)
	setMinCity(root,i,getMinSubtree(root,i));
    
    list<Node>::iterator iList;

    while (!S.empty())
    {
	w=S.top();
	S.pop();

	for(iList=getElement(w).begin(); iList!=getElement(w).end(); ++iList)
	{
	    if (ifVisited(iList->getVal())==false)
	    {
		markVisited(iList->getVal());
		S.push(iList->getVal());
	    
		for (i=1; i<=prNum; i++)
		{
		    minS=getMinSubtree(iList->getVal(),i);
		    
		    (minS != -1)?setMinCity(iList->getVal(), i, minS):
			setMinCity(iList->getVal(), i,
				   getMinCity(getParent(iList->getVal()),i));
		}
	    }
	}
    }
}

void Graph::DFS (int root)
{
    this->root=root;

    /* clear visited array first */
    initVisited();

    initMinSubtree();

    int w;

    /* S will hold list of unexplored nodes */
    stack <int> S;

    /* mark root visited*/
    markVisited (root);
    parent[root] = root;	/* origin */
    setMinSubtree(root);

    /* push root node onto stack */
    S.push(root);

    list<Node>::iterator iList;

    while (!S.empty())
    {
        w = S.top();
        S.pop();

        for (iList = getElement (w).begin();
                iList != getElement (w).end(); ++iList)
        {
            if (ifVisited (iList->getVal()) == false)
            {
                markVisited (iList->getVal());
                parent[iList->getVal()] = w;
		setMinSubtree(iList->getVal());
                S.push (iList->getVal());
            }
        }
    }
}

void Graph::initVisited ()
{
    visited.resize(nodeNum);
    visited.assign(nodeNum, false);
}

/* set 'city' as min node for product F(city) in city's parent nodes,
   if city is smaller than those nodes' current minSubtree value for F(city) */
void Graph::setMinSubtree (int city)
{
    int product=cProduct[city];
    int tempCity=city;

    /* update all the parent cities if 'city' is smaller than the
       parent cities' minSubtree value (for 'product') */
    while (tempCity!=root)
    {
	/* check if the parent node has a minSubtree value for 'product' */
	if ((getMinSubtree(tempCity, product) == -1) ||
	    (getMinSubtree(tempCity, product) > city))
	    minSubtree[tempCity-1][product]=city;
	    
	tempCity=getParent(tempCity);
    }
    
    /* for root */
    if ((getMinSubtree(tempCity, product) == -1) ||
	(getMinSubtree(tempCity, product) > city))
	minSubtree[tempCity-1][product]=city;
}

int Graph::getMinSubtree (int city, int pr)
{
    if (minSubtree[city-1].find(pr)==minSubtree[city-1].end())
	return -1;
    else
	return minSubtree[city-1][pr];
}

void Graph::initMinCity()
{
    minCity.resize(nodeNum);
}

void Graph::initMinSubtree()
{
    minSubtree.resize(nodeNum); //at() ??
}

/*
void Graph::printVisited ()
{
    for (int i = 1; i <= nodeNum; i++)
        cout << "v[" << i << "]: "
             << (visited[i - 1] ? "+" : "-") << endl;
	     }*/

bool Graph::ifVisited (int node)
{
    return visited[node-1];
}

void Graph::markVisited (int node)
{
    /* check ?? */

    visited[node - 1] = true;
}

int Node::getVal()
{
    return val;
}

void Node::setVal (int val)
{
    this->val = val;
}

void Graph::setProduct(int node, int p)
{
    cProduct[node]=p;
}
