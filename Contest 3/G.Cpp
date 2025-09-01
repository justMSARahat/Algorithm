// EOF porjonto string pair read korbo
    while (getline(cin, a) && getline(cin, b))
    {
        int n = a.size();
        int m = b.size();

        // dp array banailam size (n+1) x (m+1)
        int dp[n + 1][m + 1];

        // outer loop - string a er length onujayi
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    // base case: kono string empty hole LCS = 0
                    dp[i][j] = 0;
                }
                else if (a[i - 1] == b[j - 1])
                {
                    // match pai -> diagonal + 1
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // match na pai -> max of top/left
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // final result holo dp[n][m]
        cout << dp[n][m] << endl;
    }
}