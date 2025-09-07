#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
int visit[1001];
int n, e;

void dfs(int start)
{

    visit[start] = 1;
    cout << start << " ";
    stack<int> s;
    s.push(start);

    while (!s.empty())
    {

        for (int i = 1; i <= n; i++)
        {
            int x = s.top();
            if (visit[i] == 0 && graph[x][i] != 0)
            {

                visit[i] = 1;
                cout << i << " ";
                s.push(i);
                i = 1;
            }
        }
        s.pop();
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
    dfs(1);
}

// 5 4
// 1 2
// 1 3
// 2 4
// 3 5
// 1 2 4 3 5