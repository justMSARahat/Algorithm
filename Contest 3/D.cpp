#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S;
    // test case er number gula pori
    cin >> S;
    // each test case e loop kori
    while (S--)
    {
        string X, Y;
        // ei test case er jonne duita loop kei pori
        cin >> X >> Y;
        // X string er length
        int n = X.size();
        // Y string er length
        int m = Y.size();
        // 1-based indexing er jonne dummy character add kori
        A = '\0' + X;
        // same string Y er jonneo nei
        B = '\0' + Y;
        ////  DP matrix creat kori: dp[i][j] = min operations teke convert first i chars of X to first j chars of Y

        int dp[n + 1][m + 1];

        // Base case:  first e converting  i characters of X to empty Y(needs i deletions)
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        // Base case: converting empty X to first j characters of Y (needs j insertions)
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        // sobar jonne  Fill the DP table  i, j
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (X[i] == Y[j])
                    // characters match korle kunu operation dorkar nai
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    // character match na korle, take min of three operations + 1
                    dp[i][j] = 1 + min({// Delete from X
                                        dp[i - 1][j],
                                        // Insert into X
                                        dp[i][j - 1],
                                        // Replace
                                        dp[i - 1][j - 1]});
            }
        }

        cout << dp[n][m] << endl;
    }
}