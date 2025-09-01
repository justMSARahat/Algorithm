#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // 2ta string nei
    string a;
    string b;


    //vjudge er requirement onujayi condition.
    while (getline(cin, a) && getline(cin, b))
    {

        // loop and size er jonno length decide kori
        int n = a.size();
        int m = b.size();

        // dp array banailam size (n+1) x (m+1)
        int dp[1001][1001];

        // outer loop - string a er length onujayi cholbe
        for (int i = 0; i < n + 1; i++)
        {
            // inner loop - string b er length onujayi cholbe
            for (int j = 0; j < m + 1; j++)
            {
                // base case: jokhon kono string empty, tokhon LCS = 0
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                // jokhon match pai (a[i-1] == b[j-1]) -> ager diagonal value + 1
                else if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                // jodi match na pai, tokhon max niechi
                // 1. ager row (dp[i-1][j])
                // 2. ager column (dp[i][j-1])
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // final result holo dp[n][m]
        cout << dp[n][m] << endl;
    }
}
