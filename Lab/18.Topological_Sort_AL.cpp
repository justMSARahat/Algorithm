#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
vector<int> ans;
int visited[1001];
int n, e;

void dfs(int start)
{
    visited[start] = 1;
    for (int v = 0; v < graph[start].size(); v++)
    {
        int nd = graph[start][v];
        if (visited[nd] == 0)
        {
            visited[nd] = 1;
            dfs(nd);
        }
    }
    ans.push_back(start);
}

int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 0; i<=n; i++){
        if(visited[i] == 0 )
            dfs(i);
    }
    for(int i=ans.size()-1; i>0; i--){
        cout<<ans[i]<<" ";
    }
}


// 6 6
// 1 2
// 1 3
// 3 4
// 2 4
// 2 5
// 5 6

// 1 2 5 6 3 4
