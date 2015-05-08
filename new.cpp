#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
#define SIZE 10001
vector<int> graph[SIZE];
int product[SIZE];
int parent[SIZE];
int visited[SIZE];
int dp[SIZE][102] = {{0}};
int k;
//dp[i][j] = optimal city to visit if the current city is i and product j is needed
void dfs(int node)
{
    visited[node] = 1;
    dp[node][product[node]] = node;
    int i;
    for(i=0;i<graph[node].size();i++)
    {
        int child = graph[node][i];
        if(!visited[child])
        {
            parent[child] = node;
            dfs(child);
            int j;
            for(j=1;j<=k;j++)
            {
                //if no city if assigned for current city (dp[node][j]==0) and jth product, then assign it the same value as child node (dp[node][j] = dp[child][j])
                //or if a city has been assigned to both parent and child for jth product,
                //it means that to travel till there the min_dist from root will be same (as both paths pass through the curr node)
                //hence we choose the smaller city number (dp[node][j]>dp[child][j])
                if(dp[node][j]==0 || (dp[node][j]>dp[child][j] && dp[child][j]))
                    dp[node][j] = dp[child][j];
            }
        }
    }
}
int main()
{
    int n,capital,i,x,y,q;
    scanf("%d%d",&n,&k);
    scanf("%d",&capital);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        product[i] = x;
    }
    parent[capital] = capital;
    dfs(capital);
    scanf("%d",&q);
    while(q--)
    {
        int city,req_product;
        scanf("%d%d",&city,&req_product);
        int ans=-1;
        while(1)
        {
            //if there is some optimal city answer for current city and product
            if(dp[city][req_product])
            {
                ans = dp[city][req_product];
                break;
            }
            //if not, then check in the parent's subtree
            if(city==parent[city])
                break;
            city=parent[city];
        }
        printf("%d\n",ans);
    }
    return 0;
} 
