#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 7, 4};
    InsertionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << ",";
    }
}