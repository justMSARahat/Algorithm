#include<bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001];
int dis[1001];
int low[1001];
int isAP[1001];
int timer = 0;
int n, e;

void DFS(int u, int parent)
{
    visited[u] = 1;
    dis[u] = low[u] = ++timer;
    int children = 0;

    for (int v = 1; v <= n; v++)
    {

        if(visited[v] == 0 && graph[u][v] != 0)
        {
            children++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] >= dis[u] && parent != -1)
            {
                isAP[u] = true;
            }
        }
        else if(v != parent && graph[u][v] != 0)
        {
            low[u] = min(low[u], dis[v]);
        }



    }

    if (parent == -1 && children > 1)
    {
        isAP[u] = 1;
    }
}

int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    DFS(1, -1);

}