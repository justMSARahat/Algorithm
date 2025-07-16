#include <bits/stdc++.h>
using namespace std;

// LCS function start
void LCS(string s1, string s2)
{
    int n = s1.size(); // prothom string er size n
    int m = s2.size(); // ditiyo string er size m

    int LCS[n + 1][m + 1]; // 2D array banailam LCS calculation er jonno

    for (int i = 0; i < n + 1; i++)
    { // prothom column shob gula 0
        LCS[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++)
    { // prothom row shob gula 0
        LCS[0][j] = 0;
    }

    // DP fill kortesi
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {                                      // jodi match hoy
                LCS[i][j] = 1 + LCS[i - 1][j - 1]; // diagonal er value +1
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // up ba left theke max value
            }
        }
    }
    cout << LCS[n][m] << " "; // LCS er length print kortesi
    cout << endl;             // newline

    string ans;       // LCS string collect korar jonno
    int i = n, j = m; // last cell theke trace back korbo

    while (i > 0)
    { // jokhon porjonto i>0
        if (s1[i - 1] == s2[j - 1])
        {                             // jodi character match kore
            ans.push_back(s2[j - 1]); // answer string e add korlam
            i = i - 1;                // both index decrement
            j = j - 1;
        }
        else
        {
            if (LCS[i][j] == LCS[i - 1][j])
            { // up er value same hole up e jabo
                i = i - 1;
            }
            else
            { // na hole left e jabo
                j = j - 1;
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    { // reverse print kortesi
        cout << ans[i];
    }
}

// Edit Distance function start
void EditDistance(string s1, string s2)
{
    int m = s1.size(), n = s2.size(); // size ber kortesi
    s1 = '\0' + s1;                   // ekta dummy character add korlam index match er jonno
    s2 = '\0' + s2;                   // same ekhaneo
    int edit_dis[n + 1][m + 1];       // 2D array for edit distance

    for (int i = 0; i < n + 1; i++)
    {                                   // row loop
        for (int j = 0; j < m + 1; j++) // column loop
        {
            if (j == 0)
            {                       // first column
                edit_dis[i][j] = i; // row number assign
            }
            else if (i == 0) // first row
            {
                edit_dis[i][j] = j; // column number assign
            }
            else if (s1[j] == s2[i]) // jodi match kore
            {
                edit_dis[i][j] = edit_dis[i - 1][j - 1]; // diagonaler value copy
            }
            else // mismatch
            {
                int mn = min(edit_dis[i - 1][j], edit_dis[i][j - 1]); // insert/delete minimum ber korchi
                edit_dis[i][j] = 1 + min(mn, edit_dis[i - 1][j - 1]); // 1 plus kore minimum ta assign
            }
        }
    }

    for (int i = 0; i < n + 1; i++) // edit distance matrix print kortesi
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << edit_dis[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Minimum edit distance " << edit_dis[n][m] << endl; // final edit distance print

    int i = n, j = m;      // trace back er jonno
    while (i > 0 && j > 0) // jokhon duto index zero na
    {
        if (s1[j] == s2[i]) // jodi match kore
        {
            i--; // just move diagonally
            j--;
        }
        else // na hole operation korbo
        {
            if (edit_dis[i][j] - 1 == edit_dis[i - 1][j - 1]) // replace case
            {
                cout << "Replace op: " << s1[j] << "--" << s2[i] << endl;
                i--;
                j--;
            }
            else if (edit_dis[i][j] - 1 == edit_dis[i][j - 1]) // delete case
            {
                cout << "Delete op: " << s1[j] << "is deleted" << endl;
                j--;
            }
            else // insert case
            {
                cout << "Insert op: " << s2[i] << "is inserted" << endl;
                i--;
            }
        }
    }
}

// main function
int main()
{
    string s1, s2;    // 2 ta string nibo
    getline(cin, s1); // first string input
    getline(cin, s2); // second string input
    char choice;      // L or E input nibo
    cin >> choice;    // user choice nichi
    if (choice == 'L' || choice == 'l')
    {                // jodi L dey
        LCS(s1, s2); // LCS function call
    }
    else if (choice == 'E' || choice == 'e')
    {                         // jodi E dey
        EditDistance(s1, s2); // Edit Distance call
    }
    else
    {                                      // invalid choice
        cout << "Invalid choice!" << endl; // error print
    }

    return 0; // program end
}
