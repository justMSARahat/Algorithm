#include <bits/stdc++.h>
using namespace std;

void Marge(int A[], int B[], int C[], int m, int n, int k)
{
    int x = 0; // A and m
    int y = 0; // B and n
    int z = 0; // C and k

    while (x < m && y < n)
    {

        if (A[x] < B[y])
        {
            C[z] = A[x];
            z++;
            x++;
        }
        else
        {
            C[z] = B[y];
            z++;
            y++;
        }
    }
    for (; x < m; x++)
    {
        C[z] = A[x];
        z++;
    }
    for (; y < n; y++)
    {
        C[z] = B[y];
        z++;
    }
}

int main()
{
    // Array 1
    int m;
    cout << "Array One Element" << endl;
    cin >> m;
    int A[m];
    cout << "Enter Array 1" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    cout << "Array 1" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    // Array 2
    int n;
    cout << "Array Two Element" << endl;
    cin >> n;
    int B[n];
    cout << "Enter Array 2" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    cout << "Array 2" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << "***********************" << endl;
    cout << endl;

    // Marged Array
    int k = m + n;
    int C[k];

    Marge(A, B, C, m, n, k);

    cout << "Final Marged Array" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << C[i] << " ";
    }
}