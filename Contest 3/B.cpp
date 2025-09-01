#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// start main function
int main()
{
    // duita string re store kori
    string a1, a2; //
    // EOF porjonto jura string niye
    while (cin >> a1 >> a2)
    {
        // first string er length
        int n = a1.size();
        // second string er length
        int m = a2.size();
        // DP table er jonne 2D array nei ,LCS value
        int LCS[n + 1][m + 1];
        // protom colum 0 teke start kore
        for (int i = 0; i <= n; i++)
        {
            LCS[i][0] = 0;
        }
        // protom row 0 teke start kore
        for (int j = 0; j <= m; j++)
        {
            LCS[0][j] = 0;
        }

        // first string er upor loop
        for (int i = 1; i <= n; i++)
        {
            // second string er upor loop
            for (int j = 1; j <= m; j++)
            {
                // jodi characters match kore
                if (a1[i - 1] == a2[j - 1])
                {
                    // tahole Diagonal +1
                    LCS[i][j] = 1 + LCS[i - 1][j - 1];
                }
                // jodi chaaracters natch na kore
                else
                {
                    // sorbucco  top or left
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // Max of top/left
                }
            }
        }
        // final LCS length print kori
        cout << LCS[n][m] << endl;
    }

    return 0;
}