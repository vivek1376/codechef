#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <limits>
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
    int V;			/* root */
    vector <list <Node> > g;
    unordered_map <int, vector <bool> > visited; /* each element stores a
						    particular DFS instance
						    result */
    unordered_map <int, vector <int> > distance; /* distances from a starting
						    vertex */
    unordered_map <int, unordered_map <int, int> > parent; /* store parent node
							      for each DFS instance*/

    /* store min node in subtree having product p (under
       a particular root node) */
    unordered_map <int, vector <unordered_map<int , int > > > minSubtree;
    unordered_map <int ,int> cProduct;
public:
    Graph (int V);
    void DFS (int v);
    int returnCapacity();
    void addEdge (int v, int w);
    int getMinSubtree(int root, int v);
    vector <list <Node> >::reference getElement (int n);
    void markVisited (int v, int node);
    void setDistance (int v, int w , int dist);
    void setMinSubtree (int root, int v);
    int getDistance (int v, int w);
    int getParent (int v, int w);
    void initDistance (int v);
    void initMinStree(int v);
    bool ifVisited (int v, int node);
    void printVisited (int v);
    void printDistances (int v);
    void printPath (int v, int d);
    void setProduct(int v, int p);
    list <Node>::iterator returnList (int node);
};

int main()
{
    int N, K, B, i, m, n, x, y, Nq;
    cin >> N >> K;
    cin >> B;

    Graph myGraph (N);

    i = N - 1;

    while (i--)
    {
        cin >> x >> y;
        myGraph.addEdge (x, y);
    }

    //unordered_map <int, int> F;
    unordered_map <int, vector <int> > pCities;
    for (i = 0; i < N; i++)
    {
        cin >> m;
	myGraph.setProduct(i+1,m);
        //F[i + 1] = m;		/* map city with product */
        pCities[m].push_back (i + 1);
    }

    cin >> Nq;			/* no of queries */

    myGraph.DFS (B);		/* DFS from capital */
    cout<<"dp"<<myGraph.getMinSubtree(B,7)<<endl;
    for (i = 0; i < Nq; i++)
    {
        cin >> m >> n;

        /* no city */
        if (pCities.find (n) == pCities.end())
        {
            cout << "-1" << endl;
            continue;
        }
        else if (pCities[n].size() == 1)
        {   /* product found in only one city */
            cout << pCities[n][0] << endl;
            continue;
        }
        // if own city ??

        /* multiple city choices */
        myGraph.DFS (m);		/* DFS from chef's city */

        int d,
            p = numeric_limits<int>::min(),
            maxCityD = numeric_limits<int>::min(),
            minL = numeric_limits<int>::max(),
            maxCity = numeric_limits<int>::max();

        /* iterate all product cities */
        for (vector<int>::iterator iVec = pCities[n].begin();
                iVec != pCities[n].end(); ++iVec)
        {
            p = -1, d = *iVec;
            minL = numeric_limits<int>::max(); /* initialize */
            minL = MIN (minL, myGraph.getDistance (B, d));
            while (p != m)
            {
                p = myGraph.getParent (m, d);
                d = p;
                minL = MIN (minL, myGraph.getDistance (B, d));
            }

            /* max city */
            if (minL > maxCityD)
            {
                maxCityD = minL;
                maxCity = *iVec;
            }
            else if (maxCityD == minL)
                maxCity = MIN (maxCity, *iVec);
        }
        cout << maxCity << endl; //??OK
    }
}

Node::Node()
{
    this->visited = 0;
}

int Graph::getParent (int v, int w)
{
    return this->parent[v][w];
}

void Graph::printPath (int v, int d)
{
    /* add checking */
    int p = -1;

    cout << "path: " << d;
    while (p != v)
    {
        p = this->parent[v][d];
        d = p;
        cout << " " << d;
    }
    cout << endl;
}

Graph::Graph (int V)
{
    this->g.resize (V);
    this->V = V;
}

int Graph::returnCapacity()
{
    return this->g.size();
}

vector <list <Node> >::reference Graph::getElement (int n)
{
    return this->g[n - 1];
}

void Graph::addEdge (int v, int w)
{
    Node n;
    n.setVal (w);
    this->getElement (v).push_back (n);

    /* bidirectional edge */
    n.setVal (v);
    this->getElement (w).push_back (n);
}

void Node::setVal (int val)
{
    this->val = val;
}

int Graph::getMinSubtree(int root, int v)
{
    return this->minSubtree[root][v-1][this->cProduct[v]];
}

void Graph::DFS (int v)
{
    if (this->visited.find (v) != this->visited.end()) /* important!! */
        return;
    
//    this->minSubtree.insert(make_pair(this->V,make_pair(
    initMinStree(v);

    /* clear visited array first */
    this->visited.insert (make_pair (v, vector <bool> (this->V, false))); //check
    int w, dist = 0;

    initDistance (v);
    stack <int> S;

    /* mark v visited,
       why not pushing into stack ?? */
    this->markVisited (v, v);
    this->parent[v][v] = v;	/* origin */
    setMinSubtree(v, v); /* set */
    this->setDistance (v, v, dist);

    list<Node>::iterator iList;

    /* push all nodes adjacent to v onto S */
    for (iList = this->getElement (v).begin(), ++dist; /* increment dist by 1 */
            iList != this->getElement (v).end(); ++iList)
    {
        this->markVisited (v, iList->getVal());
        this->setDistance (v, iList->getVal(), dist);
        this->parent[v][iList->getVal()] = v;
	setMinSubtree(v,iList->getVal());
        S.push (iList->getVal());
    }

    while (!S.empty())
    {
        w = S.top();
        S.pop();
        dist = getDistance (v, w);	/* OK?? */

        for (iList = this->getElement (w).begin(), ++dist;
                iList != this->getElement (w).end(); ++iList)
        {
            if (this->ifVisited (v, iList->getVal()) == false)
            {
                this->markVisited (v, iList->getVal());
                this->setDistance (v, iList->getVal(), dist);
                this->parent[v][iList->getVal()] = w;
		setMinSubtree(v,iList->getVal());
                S.push (iList->getVal());
            }
        }
    }
}

int Graph::getDistance (int v, int w)
{
    return this->distance[v][w - 1]; /* at() ?? */
}

void Graph::setDistance (int v, int w, int dist)
{
    this->distance[v][w - 1] = dist;
}

void Graph::setMinSubtree(int root, int v)
{
    int city=v;
    while (this->parent[root][city]!=root)
    {
	if (minSubtree[root][city-1].find(this->cProduct[city])==
	    minSubtree[root][city-1].end())
	    this->minSubtree[root][city-1][this->cProduct[city]]=v;
	else if (minSubtree[root][city-1][this->cProduct[city]] > v)
	    this->minSubtree[root][city-1][this->cProduct[city]]=v;
	
	city=getParent(root,city);
    }
    
    /* for root */
    if (minSubtree[root][city-1].find(this->cProduct[city])==
	minSubtree[root][city-1].end())
	this->minSubtree[root][city-1][this->cProduct[city]]=v;
    else if (minSubtree[root][city-1][this->cProduct[city]] >
	     v)
	this->minSubtree[root][city-1][this->cProduct[city]]=v;
	
}

void Graph::setProduct(int v, int p)
{
    this->cProduct[v]=p;
}

void Graph::initMinStree(int v)
{
    this->minSubtree[v].resize(this->V); //at() ??
}

void Graph::initDistance (int v)
{
    this->distance[v].resize (this->V); /* here OK?? */
    this->distance[v].assign (this->distance[v].size(), -1);
}

void Graph::printVisited (int v)
{
    for (int i = 1; i <= this->V; i++)
        cout << "v[" << i << "]: "
             << (this->visited[v][i - 1] ? "+" : "-") << endl;
}

void Graph::printDistances (int v)
{
    for (int i = 1; i <= this->V; i++)
        cout << "d[" << i << "]: " << this->distance[v][i - 1] << endl;
}

bool Graph::ifVisited (int v, int node)
{
    return this->visited[v][node - 1]; /* correct behaviour if
					v not present ??
					use (at) ?? */
}

void Graph::markVisited (int v, int node)
{
    /* check ?? */

    this->visited[v][node - 1] = true;
}

list <Node>::iterator Graph::returnList (int node)
{
    return this->g[node - 1].begin();
}

int Node::getVal()
{
    return this->val;
}
