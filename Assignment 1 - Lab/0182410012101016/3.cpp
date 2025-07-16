#include <bits/stdc++.h>
using namespace std;

// coin change function start
void coinchange()
{
    int n, m;                   // n holo coin type er songkha, m holo amount
    cin >> n >> m;              // n and m input nicchi
    int coin[n];                // coin array declare kortesi
    for (int i = 0; i < n; i++) // prottek coin input nicchi
    {
        cin >> coin[i];
    }
    long long int dp_coin[n + 1][m + 1]; // dp array declare korlam coin change er jonno

    for (int i = 0; i < n + 1; i++) // prottek row er 0th column 0 kore dicchi
    {
        dp_coin[i][0] = 0;
    }
    for (int j = 1; j < m + 1; j++) // 0th row er baki gula INT_MAX set kortesi
    {
        dp_coin[0][j] = INT_MAX;
    }

    for (int i = 1; i < n + 1; i++) // DP te loop chalacchi
    {
        for (int j = 1; j < m + 1; j++) // prottek cell check kortesi
        {
            if (coin[i - 1] > j) // jodi coin ta amount er cheye boro hoy
            {
                dp_coin[i][j] = dp_coin[i - 1][j]; // previous value use kortesi
            }
            else // coin use kora jabe
            {
                dp_coin[i][j] = min(dp_coin[i - 1][j], 1 + dp_coin[i][j - coin[i - 1]]); // min ber kortesi
            }
        }
    }

    cout << "Minimum number of coins: " << dp_coin[n][m] << endl; // result print kortesi

    int i = n, j = m; // coin selection dekhar jonno initialization
    while (i > 0)     // jodi coin thake
    {
        while (dp_coin[i][j] != dp_coin[i - 1][j]) // jokhon value change hoise mane coin use hoise
        {
            j = j - coin[i - 1];                           // amount theke coin minus
            cout << coin[i - 1] << " is selected" << endl; // coin print kortesi
            continue;                                      // abar loop e jabo
        }
        i = i - 1; // next coin check
    }
}

// 0/1 Knapsack function start
void zeroone()
{
    int n, m;                   // n holo object er songkha, m holo bag capacity
    cin >> n >> m;              // input nicchi
    int profit[n];              // profit array
    int weight[n];              // weight array
    for (int i = 0; i < n; i++) // profit input
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++) // weight input
    {
        cin >> weight[i];
    }

    int sack[n + 1][m + 1];         // DP array declare kortesi
    for (int i = 0; i < n + 1; i++) // sob row er 0th column 0
    {
        sack[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++) // 0th row er sob column 0
    {
        sack[0][j] = 0;
    }

    for (int i = 1; i < n + 1; i++) // DP fill korar loop
    {
        for (int j = 1; j < m + 1; j++) // column loop
        {
            if (weight[i - 1] > j) // weight boro hole ager value nibo
            {
                sack[i][j] = sack[i - 1][j];
            }
            else // weight choto hole max ber korbo
            {
                sack[i][j] = max(sack[i - 1][j], sack[i - 1][j - weight[i - 1]] + profit[i - 1]);
            }
        }
    }

    cout << "Maximum profit " << sack[n][m] << endl; // final profit print

    int i = n, j = m; // object trace korar jonno
    while (i > 0)     // jotokhon object ase
    {
        if (sack[i][j] == sack[i - 1][j]) // object ta neya hoy nai
        {
            i = i - 1; // next object
            continue;  // skip
        }
        else // object neya hoise
        {
            cout << "Product " << i << " is selected" << endl; // object print
            j = j - weight[i - 1];                             // weight theke minus
            i = i - 1;                                         // next object
        }
    }
}

// main function
int main()
{
    char choice;                                                   // user input nibo 0 naki C
    cout << "Enter '0' for 0/1 Knapsack or 'C' for Coin Change: "; // option bolchi
    cin >> choice;                                                 // input nicchi

    if (choice == '0') // jodi 0 dey
    {
        zeroone(); // 0/1 knapsack call
    }
    else if (choice == 'C') // jodi C dey
    {
        coinchange(); // coin change call
    }
    else // vul input
    {
        cout << "Invalid input.Please enter '0' or 'C'" << endl; // error message
    }
}
