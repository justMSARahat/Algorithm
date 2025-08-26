#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int weight[n], profit[n];

    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < m + 1; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (w >= weight[i - 1])
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + profit[i-1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < m + 1; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
    cout<<"Max Profit - "<<dp[n][m];
}
