#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visit[1001];
int n, e;

void dfs(int start)
{
    visit[start] = 1;
    cout << start << " ";
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0 && graph[start][i] != 0)
        {
            dfs(i);
            visit[i] = 1;
        }
    }
}

int main(){
    cin>>n>>e;
    int u, v;
    for(int i = 0; i<e; i++){
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    dfs(1);
}