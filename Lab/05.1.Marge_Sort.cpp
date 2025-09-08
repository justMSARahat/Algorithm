#include <bits/stdc++.h>
using namespace std;

void Marge(int l, int mid, int h, int array[], int sort[])
{
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= h)
    {
        if (array[i] < array[j])
        {
            sort[k] = array[i];
            i++;
            k++;
        }
        else
        {
            sort[k] = array[j];
            j++;
            k++;
        }
    }
    for (; i <= mid; i++)
    {
        sort[k] = array[i];
        k++;
    }
    for (; j <= h; j++)
    {
        sort[k] = array[j];
        k++;
    }
    for (int t = l; t <= h; t++)
    {
        array[t] = sort[t];
    }
}
void MargeSort(int array[], int l, int h, int sort[])
{
    if (l < h)
    {
        int mid = (h + l) / 2;
        MargeSort(array, l, mid, sort);
        MargeSort(array, mid + 1, h, sort);
        Marge(l, mid, h, array, sort);
    }
}
int main()
{
    // Array
    int x;
    cout << "Number of Element" << endl;
    cin >> x;
    int array[x];
    int sort[x];
    cout << "Enter Array's Element" << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> array[i];
    }

    // Output
    cout << endl;
    cout << "***********************" << endl;
    cout << "*******MargeSort*******" << endl;
    cout << "***********************" << endl;
    cout << endl;

    MargeSort(array, 0, x - 1, sort);

    for (int i = 0; i < x; i++)
    {
        cout << array[i] << " ";
    }
}
