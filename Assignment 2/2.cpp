#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1001];
int visit[1001];
int n, e;

void Stack(int start)
{
    visit[start] = 1;
    cout << start << " ";
    stack<int> S;
    S.push(start);

    while (!S.empty())
    {
        int x = S.top();

        for (int j = 0; j < graph[x].size(); j++)
        {
            int node = graph[x][j].first;

            if (visit[node] == 0)
            {
                visit[node] = 1;
                cout << node << " ";
                S.push(node);

                j = 0;
                x = S.top();
            }
        }
        S.pop();
    }
}

int main()
{
    cin >> n >> e;
    int u, v, w;

    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // directed edge
    }

    Stack(1);

    return 0;
}