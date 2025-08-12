#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 7, 4};
    SelectionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << ",";
    }
}