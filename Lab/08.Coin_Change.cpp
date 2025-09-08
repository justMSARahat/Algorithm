#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if ((i == 0 && j == 0) || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            else if (j >= coin[i-1])
            {
                dp[i][j] = min(
                    dp[i - 1][j],
                    1 + dp[i][j - coin[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // max profit
    cout << dp[n][m] << " Max";

    int i = n, j = m;
    while(i>0){
        if(dp[n][m] != dp[i-1][j]){
            cout<<coin[i-1]<<" Selected";
            j = j - coin[i - 1];
        }
        i--;
    }
}