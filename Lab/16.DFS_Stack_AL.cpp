#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visited[1001];
int n, e;

void dfs(int start)
{
    visited[start] = 1;
    cout << start << " ";
    stack<int> q;
    q.push(start);

    while (!q.empty())
    {
        for (int i = 0; i < graph[start].size(); i++)
        {
            int x = q.top();
            int nd = graph[x][i];
            if (visited[nd] == 0)
            {
                dfs(nd);
                visited[nd] = 1;
            }
        }
        q.pop();
    }
}



int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
}

// 5 4
// 1 2
// 1 3
// 2 4
// 3 5
// 1 2 4 3 5