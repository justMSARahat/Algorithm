#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// using library function
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string A, B;
        cin >> A >> B;

        int n = A.size(); // string A size
        int m = B.size(); // string B size

        A = '\0' + A; // Add a null character
        B = '\0' + B; // Same for string B

        int dp[n + 1][m + 1]; // dp matrix

        for (int i = 0; i <= n; i++)
            dp[i][0] = i; // using 1st loop

        for (int j = 0; j <= m; j++)
            dp[0][j] = j; // using 2nd loop

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1]; // jdi char match hoy tahole operator lagbe na
                else
                    dp[i][j] = 1 + min({dp[i - 1][j],
                                        dp[i][j - 1],
                                        dp[i - 1][j - 1]});
            }
        }

        cout << dp[n][m] << endl; // print
    }
}
