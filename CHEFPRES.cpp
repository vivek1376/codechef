#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>

using namespace std;

class Node{
private:
    int val;
    char visited;
    /* map for dfs from each vertex */
public:
    Node();
    void setVal(int val);
    int getVal();
    bool ifVisited();
};

class Graph{
private:
    int V;
    vector <list <Node> > g;
    map <int, vector <bool> > visited; /* each element stores a 
					  particular DFS instance
					  result */
    map <int, vector <int> > distance; /* distances from a starting
					  vertex */
    map <int, map <int, int> > parent; /* store parent node
					  for each DFS instance*/
public:
    Graph(int V);
    void DFS(int v, int d);
    int returnCapacity();
    void addEdge(int v, int w);
    vector <list <Node> >::reference getElement(int n);
    void markVisited(int v, int node);
    void setDistance(int v,int w , int dist);
    int getDistance(int v, int w);
    void initDistance(int v);
    bool ifVisited(int v, int node);
    void printVisited(int v);
    void printDistances(int v);
    void printPath(int v, int d);
    list <Node>::iterator returnList(int node);
};

int main()
{
//    check map;
/*    map <int, char > mm;
      cout<<"map: "<<mm.at(2)<<endl;*/
    int N,K,B,i,j,k,v,m,n,x,y,Nq;
    cin>>N>>K;
    cin>>B;

    Graph myGraph(N);    
    cout<<"hell"<<endl;
    i=N-1;

    while(i--)
    {
	cin>>x>>y;
	myGraph.addEdge(x,y);
    }

    vector<int> F(N);
    map <int, vector <int> > cities;
    for(i=0;i<N;i++)
    {
	cin>>m;
	F[i]=m;
	cities[m].push_back(i+1);
    }

    cin>>Nq;

    vector <pair <int, int> > Q(Nq);
    for(i=0;i<Nq;i++)
    {
	cin>>m>>n;
	Q[i].first=m;		/* chef's city */
	Q[i].second=n;		/* product needed */

	/* solution */
	if(cities.find(n)==cities.end())
	    cout<<"-1"<<endl;
	else if(cities[n].size()==1)
	{
	    //cout<<cities[n][0]<<endl;
	    continue;
	}

	/* multiple city choices */
	
    }
    
    //cout<<Q[3].second;//d
//    cout<<Q[
//    cout<<myG.returnCapacity();//d
    //  cout<<endl<<sizeof(myGraph);
//    cout << endl<<"no of elements "<<myG. //d

/*    for(i=1;i<=N;i++)
      cout<<"visited("<< i << "): " << myGraph.ifVisited(1,i) << endl;*/

    /* run DFS */
    myGraph.DFS(1,5);    
    myGraph.printVisited(1);
    myGraph.printDistances(1);
    myGraph.printPath(1,6);
}

Node::Node()
{
    this->visited=0;
}

void Graph::printPath(int v, int d)
{
//    cout<<this->parent<<endl;
    /* add checking */
    int p=-1;

    cout<<"path: "<<d;
    while(p!=v)
    {
	p=this->parent[v][d];
	d=p;
	cout<<" "<<d;
    }
    cout <<endl;
}

Graph::Graph(int V)
{
    this->g.resize(V);
    this->V=V;
}

int Graph::returnCapacity()
{
    return this->g.size();
}

vector <list <Node> >::reference Graph::getElement(int n)
{
    return this->g.at(n-1);
}

void Graph::addEdge(int v, int w)
{
    Node n;
    n.setVal(w);
    this->getElement(v).push_back(n);

    /* bidirectional edge */
    n.setVal(v);
    this->getElement(w).push_back(n);
}

void Node::setVal(int val)
{
    this->val=val;
}


void Graph::DFS(int v, int d)
{
//    vector <bool> visited(this->V);
    //  visited.assign(visited.size(),false); /* initialize */
    
//    vector <int> distance(this->V);
//    this->visited[v].push_back(true);//d
    this->visited.insert(make_pair(v,vector <bool> (this->V,false))); //check
    int w,dist=0;

    initDistance(v);
    stack <int> S;    

//    this->distance[v].resize(this->V); /* here OK?? */
    /* mark v visited,
       why not pushing into stack ?? */
    this->markVisited(v,v);
    this->parent[v][v]=v;	/* origin */
    //cout<<"visited: "<<v<<endl;//d
    this->setDistance(v,v,dist);
    
    list<Node>::iterator iList;

    /* push all nodes adjacent to v onto S */
    for(iList=this->getElement(v).begin(), ++dist; /* increment dist by 1 */
	iList!=this->getElement(v).end(); ++iList)
    {
	this->markVisited(v,iList->getVal());
	this->setDistance(v,iList->getVal(),dist);
	this->parent[v][iList->getVal()]=v;
//	cout<<"visited: "<<iList->getVal()<<endl;//d
	S.push(iList->getVal());
    }

    while(!S.empty())
    {
	w=S.top();
	S.pop();
	dist=getDistance(v,w);	/* OK?? */
	
	for(iList=this->getElement(w).begin(),++dist; 
	    iList!=this->getElement(w).end(); ++iList)
	{
	    if(this->ifVisited(v,iList->getVal())==false)
	    {
//		cout<<"dist:"<<dist<<endl;//d
		this->markVisited(v,iList->getVal());
		this->setDistance(v,iList->getVal(),dist);
		this->parent[v][iList->getVal()]=w;
//		cout<<"visited: "<<iList->getVal()<<endl;//d
		S.push(iList->getVal());
	    }
	}
    }
    /*   int i;
    for(i=1;i<=this->V;i++)//d
    cout<<"distance("<<i<<"): "<<this->getDistance(1,i)<<endl;*/
}

int Graph::getDistance(int v, int w)
{
    return this->distance[v][w-1];
}

void Graph::setDistance(int v, int w, int dist)
{
//    cout<<"setD()"<<endl;//vector not allocated
    this->distance[v][w-1]=dist;
//    cout<<"~setD()"<<endl;
}

void Graph::initDistance(int v)
{
    this->distance[v].resize(this->V); /* here OK?? */
    this->distance[v].assign(this->distance[v].size(),-1);
}
 
void Graph::printVisited(int v)
{
    for(int i=1;i<=this->V;i++)
	cout<<"v["<<i<<"]: "
	    <<(this->visited.at(v)[i-1]?"+":"-")<<endl;
}

void Graph::printDistances(int v)
{
    for(int i=1;i<=this->V;i++)
	cout<<"d["<<i<<"]: "<<this->distance.at(v)[i-1]<<endl;
}

bool Graph::ifVisited(int v, int node)
{
    return this->visited[v][node-1]; /* correct behaviour if 
					v not present ?? 
					use (at) ?? */
}

void Graph::markVisited(int v, int node)
{
    /* check ?? */

    this->visited[v][node-1]=true;
}

list <Node>::iterator Graph::returnList(int node)
{
    return this->g[node-1].begin();
}

int Node::getVal()
{
    return this->val;
}
