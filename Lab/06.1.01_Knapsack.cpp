#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int profit[n], weight[n];
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
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= weight[i - 1])
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i - 1][j - weight[i - 1]] + profit[i - 1]);
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
    cout << "Max Profit: ";
    cout << dp[n][m]<<endl;
    //selected objects
    int i = n;
    int j = m;
    while(i>0){
        if( dp[i][j] != dp[i-1][j] ){
            cout<<i<<" Is Selected"<<endl;
            j = j - weight[i - 1];
        }
        i--;
    }
}