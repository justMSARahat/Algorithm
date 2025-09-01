#include <bits/stdc++.h>
using namespace std;
int graph[1001][1001];
int visited[1001];
int n, e;
vector<int> ans;

void dfs(int start)
{
    visited[start] = 1;

    for (int j = 1; j <= n; j++)
    {
        if (visited[j] == 0 && graph[start][j] != 0)
        {
            visited[j] = 1;
            dfs(j);
        }
    }
    ans.push_back(start);
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
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}
