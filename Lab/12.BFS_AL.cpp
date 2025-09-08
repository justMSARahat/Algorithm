#include <bits/stdc++.h>
using namespace std;

vector<int>graph[1001];
int visited[1001];
int n, e;

void bfs(int start)
{
    visited[start] = 1;
    cout << start << " ";
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && graph[x][i] != 0)
            {
                visited[i] = 1;
                cout << i << " ";
                q.push(i);
            }
        }
    }
}

int main(){
    cin>>n>>e;
    int u,v;
    for(int i=0; i<e; i++){
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    bfs(1);
}

// 5 4
// 1 2
// 1 3
// 2 4
// 3 5
// 1 2 3 4 5