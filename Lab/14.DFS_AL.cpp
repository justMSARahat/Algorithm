#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int visit[1001];
int n, e;

void dfs(int start)
{
    visit[start] = 1;
    cout << start << " ";
    for (int i = 0; i < graph[start].size(); i++)
    {
        int nd = graph[start][i];
        if (visit[nd] == 0)
        {
            dfs(nd);
            visit[nd] = 1;
        }
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