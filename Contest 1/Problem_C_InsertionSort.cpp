#include<bits/stdc++.h>
using namespace std;

// Making funcion for printing the output.
void prnt(int arr[], int x) {
    // Looop for output printing
    for(int i = 0; i < x; i++) {
        cout << arr[i];
        // Validation
        if(i<x-1){
            cout<<" ";
        }
    }
    cout<<endl;
}

void insertionSort(int arr[], int x){
    // Printing the array
    prnt(arr, x);
    // Sort Algorithm
    // first loop for locking on one item
    for(int i = 1; i<x; i++){
        // declearing items
        int current = arr[i];
        int prev = i-1;
        //loop for sorting. where array is sorted
        while(prev>=0 && arr[prev]>current){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
        prnt(arr, x);
    }
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
    insertionSort(arr, x);

    return 0;
}