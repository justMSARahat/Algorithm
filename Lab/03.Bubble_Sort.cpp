#include <bits/stdc++.h>
using namespace std;

void Bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 7, 4};
    Bubble_Sort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << ",";
    }
}