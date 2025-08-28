#include <bits/stdc++.h>
using namespace std;

int main()
{
    string string1, string2;
    getline(cin, string1);
    getline(cin, string2);

    int m = string1.size();
    int n = string2.size();

    string1 = '\0' + string1;
    string2 = '\0' + string2;

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (string1[j] == string2[i])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int x = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = 1 + min(x, dp[i - 1][j - 1]);
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

    cout << "Minimum Edit Distance -> " << dp[n][m] << endl;

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (string1[j] == string2[i])
        {
            i--;
            j--;
        }
        else
        {
            if (dp[i][j] - 1 == dp[i - 1][j - 1])
            {
                cout << "Replaced -> " << string1[j] << " -> " << string2[i] << endl;
                i--;
                j--;
            }
            else if (dp[i][j] - 1 == dp[i][j - 1])
            {
                cout << "Deleted -> " << string1[j] << endl;
                j--;
            }
            else if (dp[i][j] - 1 == dp[i - 1][j])
            {
                cout << "Inserted -> " << string2[i] << endl;
                i--;
            }
        }
    }
}