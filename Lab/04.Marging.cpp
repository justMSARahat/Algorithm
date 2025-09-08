#include <bits/stdc++.h>
using namespace std;

void Marge(int m[], int n[], int k[], int a, int b)
{
    int i = 0; // m;
    int j = 0; // n;
    int l = 0; // k

    while (i < a && j < b)
    {
        if (m[i] < n[j])
        {
            k[l] = m[i];
            i++;
            l++;
        }
        else
        {
            k[l] = n[j];
            l++;
            j++;
        }
    }
    for (; i < a; i++)
    {
        k[l] = m[i];
        l++;
    }
    for (; j < b; j++)
    {
        k[l] = n[j];
        l++;
    }
}

int main()
{
    int a = 5, b = 4, c = 9;

    int m[5] = {2,5,8,15,16};
    int n[4] = {3,4,10,14};
    int k[9] = {};

    Marge(m, n, k, a, b);
    for (int i = 0; i < 9; i++)
    {
        cout << k[i] << ",";
    }
}