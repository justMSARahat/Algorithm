#include <iostream>  // input-output er jonno
#include <string>    // string header (ekhane lagbe na, but rakha jabe)
#include <algorithm> // algorithm header (lagbe na ekhane)
#include <vector>    // vector use korar jonno
using namespace std;
const int MAXN = 7500;
long long dp[MAXN];
int coins[5] = {50, 25, 10, 5, 1};
int main()
{
    // ekhane dp initialize korbo
    dp[0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = coins[i]; j < MAXN; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    // ekhane input nibo
    int n;
    while (cin >> n)
    {
        cout << dp[n] << "\n";
    }
}