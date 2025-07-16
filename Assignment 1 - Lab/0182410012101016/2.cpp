#include <bits/stdc++.h>
using namespace std;

struct knap
{
    int object; // kon object ta represent kortese
    double PbW; // Profit by Weight ratio
};

// Profit by Weight compare korar jonno function
bool comparePbW(knap n1, knap n2)
{
    if (n1.PbW > n2.PbW)
        return true; // jodi prothom tar ratio boro hoy tahole true
    else
        return false; // na hole false
}

// greedy knapsack function
void greedyknapsack(int n, int m, int profit[], int weights[])
{
    knap sack[n];               // knap type er array declare korlam
    for (int i = 0; i < n; i++) // sob object er jonno loop
    {
        sack[i].object = i;                                   // object number set kortesi
        sack[i].PbW = double(profit[i]) / double(weights[i]); // Profit/Weight ratio ber kortesi
    }

    sort(sack, sack + n, comparePbW); // ratio onujayi decreasing order e sort kortesi

    int RW = m;                // RW mane remaining weight = total capacity
    double X[n];               // X array te fraction rakha hobe
    memset(X, 0.0, sizeof(X)); // X array ke 0 diya initialize kortesi
    int i = 0;                 // loop er jonno counter
    while (RW > 0)             // jokhon porjonto weight ase
    {
        if (RW >= weights[sack[i].object]) // jodi full object ta nite pari
        {
            X[sack[i].object] = 1;             // full object nisi
            RW = RW - weights[sack[i].object]; // remaining weight theke baad dilam
            i++;                               // next object e jabo
        }
        else // full object nite pari nai
        {
            X[sack[i].object] = double(RW) / double(weights[sack[i].object]); // fraction nisi
            RW = 0;                                                           // capacity sesh
        }
    }
    for (int i = 0; i < n; i++) // X array print kortesi
    {
        cout << X[i] << " "; // fraction value print
    }
    cout << endl;               // ekta newline
    double maxprofit = 0;       // total profit er jonno variable
    for (int i = 0; i < n; i++) // loop diya profit add kortesi
    {
        maxprofit = maxprofit + (X[i] * double(profit[i])); // fraction onujayi profit add kortesi
    }
    cout << maxprofit << endl; // total profit print kortesi
}
int main()
{
    int t;      // test case er jonno variable
    cin >> t;   // t input nicchi
    while (t--) // t bar loop cholbe
    {
        int n, m;       // object er songkha and bag er capacity
        cin >> n >> m;  // input nicchi
        int profit[n];  // profit array
        int weights[n]; // weight array

        for (int i = 0; i < n; i++) // sob object er profit input
        {
            cin >> profit[i];
        }
        for (int i = 0; i < n; i++) // sob object er weight input
        {
            cin >> weights[i];
        }
        greedyknapsack(n, m, profit, weights); // main function call kortesi
    }
    return 0; // program end
}
