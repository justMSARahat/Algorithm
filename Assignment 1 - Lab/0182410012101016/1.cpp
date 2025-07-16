#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int x)
{
    // Looop for output printing
    for (int i = 0; i < x; i++)
    {
        cout << arr[i];
        // Validation
        if (i < x - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    cout << "***************" << endl;
    cout << "Insertion Sort" << endl;
    cout << "***************" << endl;
    // Printing Sorted Array
    for (int i = 0; i < x; i++)
    {
        cout << arr[i];
        if (i < x - 1)
            cout << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int x)
{
    // first loop
    for (int i = 0; i < x - 1; i++)
    {
        // second loop
        for (int j = 0; j <= x - i - 1; j++)
        {
            // checking numbers if big or small
            if (arr[j] < arr[j - 1])
            {
                // swapping number
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    cout << "***************" << endl;
    cout << "Buble Sort" << endl;
    cout << "***************" << endl;
    // Printing Sorted Array
    for (int i = 0; i < x; i++)
    {
        cout << arr[i];
        if (i < x - 1)
            cout << " ";
    }
    cout << endl;
}
void SelectionSort(int arr[], int x)
{

    // Selection Sort algorithm, Two nested loops.
    for (int i = 0; i < x - 1; i++)
    {
        // declearing the first element smallest
        int mini = i;
        // seraching from the second element if it is bigger or smaller
        for (int j = i + 1; j < x; j++)
        {
            // checking larger and smaller
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        if (mini != i)
        {
            swap(arr[i], arr[mini]);
        } // Only swap if a smaller element is found
    }
    cout << "***************" << endl;
    cout << "Selection Sort" << endl;
    cout << "***************" << endl;
    // Printing Sorted Array
    for (int i = 0; i < x; i++)
    {
        cout << arr[i];
        if (i < x - 1)
            cout << " ";
    }
    cout << endl;
}
#include <iostream>
using namespace std;

void quickSort(int start, int ending, int a[])
{
    if (start >= ending)
        return;

    int pivot = start, i = start, j = ending;

    while (i <= j)
    {
        while (a[i] <= a[pivot])
            i++;
        while (a[j] > a[pivot])
            j--; // when equal then break that's why we didnt use =
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[pivot], a[j]);

    quickSort(start, j - 1, a);
    quickSort(j + 1, ending, a);
}

void quickSort(int start, int ending, int a[], bool printOnce = false) {
    if (start >= ending)
        return;

    int pivot = start, i = start, j = ending;

    while (i <= j) {
        while (a[i] <= a[pivot]) i++;
        while (a[j] > a[pivot]) j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[pivot], a[j]);

    quickSort(start, j - 1, a, printOnce);
    quickSort(j + 1, ending, a, printOnce);

    // Print the result once after all the recursive calls are done
    if (printOnce) {
        cout << "***************" << endl;
        cout << "Quick Sort" << endl;
        cout << "***************" << endl;
        for (int i = 0; i <= ending; i++) {
            cout << a[i];
            if (i < ending)
                cout << " ";
        }
        cout << endl;
    }
}


void merge(int arr[], int left, int mid, int right)
{

    // two array for holding both part
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int first[n1];
    int second[n2];

    // pushing value to the array using loop
    for (int i = 0; i < n1; i++)
    {
        first[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        second[i] = arr[mid + 1 + i];
    }

    // 2 variable declearing
    int i = 0, j = 0;
    // i will traverse array 1, and j will traverse array 2;
    int k = left;
    while (i < n1 && j < n2)
    {
        // condition for checking digit
        if (first[i] <= second[j])
        {
            // if true then the value is going for the first array
            arr[k] = first[i];
            // increasing K and I
            k++;
            i++;
        }
        else
        {

            // if false then the value is going for the second array
            arr[k] = second[j];

            // increasing K and J
            k++;
            j++;
        }
    }

    // if i dont reach j
    while (i < n1)
    {
        arr[k] = first[i];
        // increasing K and I
        k++;
        i++;
    }
    // if j dont reach
    while (j < n2)
    {
        arr[k] = second[j];
        // increasing K and I
        k++;
        j++;
    }
}

void margesort(int arr[], int left, int right)
{
    // the loop will work till L < R
    if (left < right)
    {
        // Mid Declear
        int mid = (left + right) / 2;
        // sorting left side till mid
        margesort(arr, left, mid);
        // sorting right side till end from mid
        margesort(arr, mid + 1, right);

        // Marging left and right
        merge(arr, left, mid, right);
    }
    cout << "***************" << endl;
    cout << "Marge Sort" << endl;
    cout << "***************" << endl;
    // Printing Sorted Array
    for (int i = 0; i < right; i++)
    {
        cout << arr[i];
        if (i < right - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    // Taking Input for array
    int x;
    cin >> x;
    // Declaring array
    int arr[x];
    // Inputting array
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }

    // Passing array to Sort Function
    InsertionSort(arr, x);
    bubbleSort(arr, x);
    SelectionSort(arr, x);
    quickSort(0, x, arr, true);
    margesort(arr, 0, x - 1);

    return 0;
}