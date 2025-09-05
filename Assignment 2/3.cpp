#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visit[1001];
int n, e;

void BFS(int start)
{
    visit[start] = 1;
    cout << start << " ";
    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (graph[x][j] != 0 && visit[j] == 0)
            {
                visit[j] = 1;
                cout << j << " ";
                Q.push(j);
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    int u, v, w;

    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    BFS(1);

    return 0;
}