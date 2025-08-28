#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m; // N means types of coin 1,2,3,4 and eta diye coins array create korbo // m mane amount
    cin >> n >> m;

    int coin[n]; // various types er coin er input nibo
    for (int i = 1; i <= n; i++)
    { // i=1 because i=0 = 0 hobe, so 0 etake na niye direct first coin theke nicci
        cin >> coin[i];
    }

    int coins[n + 1][m + 1]; // 2d array. left ta row jekhanen types of coin exist korbe and right e column where number of coin will stored

    for (int i = 0; i < n + 1; i++)
    { // row
        for (int j = 0; j < m + 1; j++)
        { // column
            /*
                total 4 ta condition mante hobe
                1. jodi row and column 0 oy taile value zero and jodi column zero hoy taile full 0
                2. Row zero hole infinite hobe
                3. jodi column er value boro hoy, coin er size theke taile
                    min(coins[i-1][j], 1+coins[i][j-coin[i]])
                4. jodi column er value choto hoy taile uporer value bosbe
            */
            if ((i == 0 && j == 0) || j == 0)
            {
                coins[i][j] = 0;
            }
            else if (i == 0)
            {
                coins[i][j] = INT_MAX-1;
            }
            else if (j >= coin[i]){
                coins[i][j] = min(coins[i-1][j], 1+coins[i][j-coin[i]]);
            }
            else{
                coins[i][j] = coins[i-1][j];
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout<<coins[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Minimum Coin change - "<<coins[n][m];
}