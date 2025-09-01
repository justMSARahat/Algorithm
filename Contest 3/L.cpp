#include <iostream>  // input-output er jonno
#include <string>    // string header (ekhane lagbe na, but rakha jabe)
#include <algorithm> // algorithm header (lagbe na ekhane)
#include <vector>    // vector use korar jonno
#include <cstring>   // memset er jonno
using namespace std;

const int MAXN = 105;    // max node 
vector<int> graph[MAXN]; // adjacency list
bool visited[MAXN];      // visited array

// simple DFS -> ekta node theke shob connected node visit korbe
void dfs(int node)
{
    visited[node] = true;        // current node mark visited
    for (int next : graph[node]) // neighbor gula check
    {
        if (!visited[next]) // jodi unvisited neighbor thake
            dfs(next);      // recursive DFS call
    }
}

int main()
{
    // multiple graph input nibo (jotokkhon na 0 ashe)
    while (true)
    {
        int n;
        cin >> n;   // number of nodes
        if (n == 0) // input end
            break;

        // previous graph clear kore dibo
        for (int i = 1; i <= n; i++)
            graph[i].clear();

        // edge input nibo
        while (true)
        {
            int u;
            cin >> u;
            if (u == 0) // 0 ashle edge input sesh
                break;

            // u node theke onno node gula input nibo
            while (true)
            {
                int v;
                cin >> v;
                if (v == 0) // 0 ashle u er neighbor input sesh
                    break;
                graph[u].push_back(v); // directed edge: u -> v
            }
        }

        // ekhane query number input nibo
        int q;
        cin >> q;

        while (q--)
        {
            int start;
            cin >> start; // start node

            // visited reset korbo
            memset(visited, false, sizeof(visited));

            // start node er shob neighbor theke DFS chalabo
            for (int nei : graph[start])
            {
                if (!visited[nei])
                    dfs(nei);
            }

            // ekhon jara unvisited -> unreachable nodes
            vector<int> ans;
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                    ans.push_back(i);
            }

            // answer print korbo
            cout << ans.size();
            for (int x : ans)
                cout << " " << x;
            cout << "\n";
        }
    }
}
