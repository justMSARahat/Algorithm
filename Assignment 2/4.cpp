#include <bits/stdc++.h>
using namespace std;

int adjacency[1001][1001];

void Matrix(int node, int edge)
{
    int u, v;

    for (int i = 1; i <= edge; i++)
    {
        cin >> u >> v;
        adjacency[u][v] = 1;
        adjacency[v][u] = 1;
    }

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            cout << adjacency[i][j] << " ";
        }
        cout << endl;
    }
}

void List(int node, int edge)
{
    vector<int> adjacency[node + 1];
    int u, v;

    for (int i = 1; i <= edge; i++)
    {
        cin >> u >> v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    for (int i = 1; i <= node; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjacency[i].size(); j++)
        {
            cout << adjacency[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Adjacency Matrix" << endl;

    int node, edge;
    cin >> node >> edge;
    Matrix(node, edge);

    cout << "Adjacency List" << endl;

    int node, edge;
    cin >> node >> edge;
    List(node, edge);

    return 0;
}