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
public:
    Graph(int V);
    void DFS(int v);
    int returnCapacity();
    void addEdge(int v, int w);
    vector <list <Node> >::reference getElement(int n);
    void markVisited(int v, int node);
    bool ifVisited(int v, int node);
    list <Node>::iterator returnList(int node);
};

int main()
{
//    check map;
/*    map <int, char > mm;
      cout<<"map: "<<mm.at(2)<<endl;*/
    int N,K,B,i,j,k,v,w,x,y;
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

    i=N;
/*    while(i--)
    {
	
    }*/

//    cout<<myG.returnCapacity();//d
    //  cout<<endl<<sizeof(myGraph);
//    cout << endl<<"no of elements "<<myG. //d

    for(i=1;i<=N;i++)
      cout<<"visited("<< i << "): " << myGraph.ifVisited(1,i) << endl;

    /* run DFS */
    myGraph.DFS(1);    

    for(i=1;i<=N;i++)
	cout<<"visited("<< i << "): " << myGraph.ifVisited(1,i) << endl;
}

Node::Node()
{
    this->visited=0;
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

void Graph::DFS(int v)
{
//    vector <bool> visited(this->V);
    //  visited.assign(visited.size(),false); /* initialize */
    
//    vector <int> distance(this->V);
//    this->visited[v].push_back(true);//d
    this->visited.insert(make_pair(v,vector <bool> (this->V,false))); //check
    int w;

    stack <int> S;    


    /* mark v visited */
    this->markVisited(v,v);

    list<Node>::iterator iList;

    /* push all nodes adjacent to v onto S */
    for(iList=this->getElement(v).begin(); 
	iList!=this->getElement(v).end(); ++iList)
	S.push(iList->getVal());

    while(!S.empty())
    {
	w=S.top();
	S.pop();
	
	for(iList=this->getElement(w).begin(); 
	    iList!=this->getElement(w).end(); ++iList)
	{
	    if(this->ifVisited(v,iList->getVal())==false)
	    {
		this->markVisited(v,iList->getVal());
		S.push(iList->getVal());
	    }
	}
    }
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
