#include <iostream>  // input-output er jonno
#include <string>    // string header (ekhane lagbe na, but rakha jabe)
#include <algorithm> // algorithm header (lagbe na ekhane)
#include <vector>    // vector use korar jonno

using namespace std;

const int MAXN = 10005;  // maximum node number
vector<int> graph[MAXN]; // adjacency list for graph
bool visited[MAXN];      // visited array dfs er jonno

// DFS function -> ek node theke shob connected node visit korbe
void dfs(int node)
{
    visited[node] = true;        // current node ke visited mark
    for (int next : graph[node]) // oi node er neighbor gula check
    {
        if (!visited[next]) // jodi unvisited hoy
            dfs(next);      // recursive call
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges; // input nibo

    // tree hole always n-1 edges thakbe
    if (edges != nodes - 1)
    {
        cout << "NO";
        return 0;
    }

    // sob edge input nibo (undirected graph tai 2 side push kora lagbe)
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1); // node 1 theke DFS suru (assuming nodes 1-indexed)

    // jodi kono node unvisited thake tahole graph connected na
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            cout << "NO";
            return 0;
        }
    }

    // edge check + connectivity check pass korle tree
    cout << "YES";
}
