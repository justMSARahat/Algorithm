#include<bits/stdc++.h>
using namespace std;
int SelectionSort(int arr[], int x){
    int swaps = 0; // Initialize swap count

    // Selection Sort algorithm, Two nested loops.
    for(int i=0; i<x-1; i++){
        // declearing the first element smallest
        int mini = i;
        // seraching from the second element if it is bigger or smaller
        for(int j=i+1; j<x; j++){
            // checking larger and smaller
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        if(mini != i){
            swap(arr[i], arr[mini]);
            swaps++; // Increment swap count if a swap is made
        } // Only swap if a smaller element is found
    }
    return swaps;
}
int main(){
    // Taking Input for array
    int x;
    cin>>x;
    // Declaring array
    int arr[x];
    // Inputting array
    for(int i=0; i<x; i++){
        cin>>arr[i];
    }
    // Passing array to Sort Function
    int swaps = SelectionSort(arr, x);
    // Printing Sorted Array
    for(int i = 0; i < x; i++) {
        cout << arr[i];
        if(i < x - 1) cout << " ";
    }
    cout << endl;
    cout << swaps << endl;

    return 0;
}