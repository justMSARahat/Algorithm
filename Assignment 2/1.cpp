#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visited[1001];
int n, e;
vector<int> answer;

void dfs(int start)
{
    visited[start] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && graph[start][i] != 0)
        {
            visited[i] = 1;
            dfs(i);
        }
    }
    answer.push_back(start);
}

int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
    for (int i = answer.size() - 1; i >= 0; i++)
    {
        cout << answer[i] << " ";
    }
}
