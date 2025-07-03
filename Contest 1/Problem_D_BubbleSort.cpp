#include<bits/stdc++.h>
using namespace std;
int bubbleSort(int arr[], int x){
    // Bubble Sort algorithm, Two nested loops.
    int swaps = 0;
    // first loop
    for(int i = 0; i<x-1; i++){
        // second loop
        for(int j=0; j<=x-i-1; j++){
            // checking numbers if big or small
            if(arr[j]<arr[j-1]){
                // swapping number
                swap(arr[j], arr[j-1]);
                // increasing the number of time it swapping
                swaps++;
            }
        }
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
    int swaps = bubbleSort(arr, x);
    // Printing Sorted Array
    for(int i=0;i<x;i++) {
        cout<<arr[i];
        // ending 
        if(i<x-1){
            cout<<" ";
        }
    }
    cout << endl;
    cout << swaps << endl;

    return 0;
}