#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
