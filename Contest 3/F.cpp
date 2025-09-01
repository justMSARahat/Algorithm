#include <iostream>  // Input-output er jonno
#include <vector>    // Vector use korar jonno
#include <algorithm> // Max function er jonno
using namespace std;

int main()
{
    int t;
    cin >> t; // Declear a variable and input number of test cases

    while (t--) // Sob test case er jonne loop
    {
        int n;
        cin >> n; // Number of items input from users

        vector<int> ProductPrice(n), ProductWeight(n); // Sob item er price and weight store korar jonno vector

        for (int i = 0; i < n; i++)
        {
            cin >> ProductPrice[i] >> ProductWeight[i]; // Item er price and weight input
        }

        int x;
        cin >> x;          // Total people number input
        vector<int> DP(x); // Per person maximum weight capacity

        for (int i = 0; i < x; i++)
        {
            cin >> DP[i]; // Sob people er max weight input
        }

        int value = 0; // Sob people er jonno total value

        for (int z = 0; z < x; z++) // Per person knapsack solve korbo
        {
            int capacity = DP[z];            // Ei person er maximum capacity
            vector<int> dp(capacity + 1, 0); // DP array reset for each person

            for (int i = 0; i < n; i++) // Sob item check
            {
                for (int j = capacity; j >= ProductWeight[i]; j--) // Ulta dik theke loop
                {
                    dp[j] = max(dp[j], dp[j - ProductWeight[i]] + ProductPrice[i]); // Max value update
                }
            }

            value += dp[capacity]; // Ei person er max value total e add
        }

        cout << value << endl; // Output print
    }
}
