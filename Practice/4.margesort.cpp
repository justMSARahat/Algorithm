#include <bits/stdc++.h>
using namespace std;

void marge(int l, int mid, int h, int arr[], int sort[])
{
    int i = l;
    int j = mid+1;
    int k = l;

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            sort[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            sort[k] = arr[j];
            j++;
            k++;
        }
    }
    for (; i <= mid; i++)
    {
        sort[k] = arr[i];
        k++;
    }
    for (; j <= h; j++)
    {
        sort[k] = arr[j];
        k++;
    }
    for (int t = l; t <= h; t++)
    {
        arr[t] = sort[t];
    }
}
void margesort(int l, int h, int arr[], int sort[])
{

    if (l < h)
    {
        int mid = (h + l) / 2;
        margesort(l, mid, arr, sort);
        margesort(mid + 1, h, arr, sort);
        marge(l, mid, h, arr, sort);
    }
}
int main()
{
    int n = 6;
    int arr[6] = {6, 5, 4, 3, 2, 1};
    int sort[6];

    margesort(0, n - 1, arr, sort);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}