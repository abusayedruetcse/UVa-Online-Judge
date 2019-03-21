#include<iostream>
#include<vector>
using namespace std;
#define VISITED 1
#define UNVISITED 0
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


vector<vii> AdjList;
vi dfs_num;
void dfs(int u)
{
    dfs_num[u]=VISITED;
    cout<<u<<" ";
    for(int j=0;j<(int)AdjList[u].size();j++)
    {
        ii v=AdjList[u][j];
        if(dfs_num[v.first]==UNVISITED)
        {
            dfs(v.first);
        }
    }
}
int main()
{
    int V,E,u,v,w;
    cin>>V>>E;
    dfs_num.assign(V,UNVISITED);
    vector<vii> temp(V+2);
    swap(temp,AdjList);
    for(int i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        AdjList[u].push_back(make_pair(v,w));
        AdjList[v].push_back(make_pair(u,w));
    }
    dfs(1);

    return 0;
}
