#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001];
int isap[1001];
int dis[1001];
int low[1001];
int timer = 0;
int n, e;

void dfs(int u, int parent)
{
    visited[u] = 1;
    dis[u] = low[u] = ++timer;
    int child = 0;

    for (int v = 1; v <= n; v++)
    {
        if (visited[v] == 0 && graph[u][v] != 0)
        {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= dis[u])
            {
                isap[u] = true;
            }
        }
        else if (v != parent && graph[u][v] != 0)
        {
            low[u] = min(low[u], dis[v]);
        }
    }
    if (parent == -1 && child > 1)
    {
        isap[u] = true;
    }
}

int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    dfs(1, -1);
    for (int i = 0; i <= n; i++)
    {
        if (isap[i] == true)
        {
            cout << i << " AP" << endl;
        }
    }
}

// 5 5
// 1 2
// 1 3
// 3 4
// 4 5
// 3 5
// 1 Is an Ap
// 3 Is an Ap