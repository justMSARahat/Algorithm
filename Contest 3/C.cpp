#include <iostream>  // input-output er jonno
#include <string>    // string header (ekhane lagbe na, but rakha jabe)
#include <algorithm> // algorithm header (lagbe na ekhane)
#include <vector>    // vector use korar jonno
using namespace std;

int main()
{
    int T;
    cin >> T; // Number of test cases

    while (T--)
    {
        string string1, string2;
        getline(cin, string1);
        getline(cin, string2);

        int m = string1.size();
        int n = string2.size();

        string1 = '\0' + string1;
        string2 = '\0' + string2;


        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


        // Fill DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // er pore idea nai kibhabe kun condition apply korbo
            }
        }

        cout << dp[n][m] << endl;
    }
}