#include <iostream>  //Header file
#include <string>    //Header file
#include <algorithm> //Header file
#include <vector>    //Header file
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // n = number of items, m = knapsack capacity

    int weight[n], profit[n]; // item weight and profit array

    for (int i = 0; i < n; i++)
    {
        cin >> profit[i]; // each item er profit input
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i]; // each item er weight input
    }

    int dp[n + 1][m + 1]; // DP table banailam: dp[i][w] = max profit using first i items with capacity w

    // Fill the DP table
    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < m + 1; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0; // base case: kono item nai or capacity 0 → profit = 0
            }
            else if (w >= weight[i - 1])
            {
                // item include kora jabe → max of include or exclude
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + profit[i - 1]);
            }
            else
            {
                // item include kora jabe na → just exclude
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // print full DP table (for visualization)
    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < m + 1; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    cout << "Max Profit - " << dp[n][m]; // final max profit
}
