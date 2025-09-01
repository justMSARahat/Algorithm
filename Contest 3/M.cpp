#include <iostream>  // input-output er jonno
#include <string>    // string header (ekhane lagbe na, but rakha jabe)
#include <algorithm> // algorithm header (lagbe na ekhane)
#include <vector>    // vector use korar jonno
#include <cstring>   // memset er jonno
using namespace std;
const int MAXN = 10005;
vector<int> graph[MAXN];
bool visited[MAXN];
int farNode, maxDist;

// dfs function
void dfs(int node, int dist)
{
    visited[node] = true; // current node ke visited mark dilam

    // jodi present distance er cheye boro hoy tahole max update
    if (dist > maxDist)
    {
        maxDist = dist; // max distance update
        farNode = node; // oi distance er node ke farthest node hisebe save
    }

    // current node er neighbor gulake check korbo
    for (int next : graph[node])
    {
        if (!visited[next])      // jodi neighbor unvisited thake
            dfs(next, dist + 1); // recursive call, distance +1
    }
}
int main()
{
    // ekhane node input nibo
    int nodes;
    cin >> nodes;
    // ekhane tree er edge input nibo
    for (int i = 0; i < nodes - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // prothome ekta node theke dfs chalabo farthest node ber korte
    dfs(1, 0);
    // abar visited reset korbo
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    // oi farthest node theke abar dfs chalabo
    dfs(farNode, 0);
    // longest path print korbo
    cout << maxDist;
}