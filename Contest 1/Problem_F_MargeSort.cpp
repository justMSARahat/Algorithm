#include<bits/stdc++.h>
using namespace std;

// global var to count number of times
long long counnt = 0;


void merge ( int arr[], int left, int mid, int right){

    // two array for holding both part
    int n1 = mid-left+1;
    int n2 = right-mid;
    int first[n1];
    int second[n2];

    // pushing value to the array using loop
    for(int i=0; i<n1; i++){
        first[i] = arr[left+i];
    }
    for(int i=0; i<n2; i++){
        second[i] = arr[mid+1+i];
    }

    // 2 variable declearing
    int i = 0, j = 0;
    //i will traverse array 1, and j will traverse array 2;
    int k = left;
    while(i<n1 && j<n2){
        counnt++;
        //condition for checking digit
        if(first[i] <= second[j]){
            // if true then the value is going for the first array
            arr[k] = first[i];
            // increasing K and I
            k++;
            i++;
        }
        else{

            // if false then the value is going for the second array
            arr[k] = second[j];

            // increasing K and J
            k++;
            j++;
        }
    }

    // if i dont reach j
    while(i<n1){
        counnt++;
            arr[k] = first[i];
            // increasing K and I
            k++;
            i++;
    }
    // if j dont reach
    while(j<n2){
        counnt++;
            arr[k] = second[j];
            // increasing K and I
            k++;
            j++;
    }




}

void margesort(int arr[], int left, int right){
    // the loop will work till L < R
    if(left<right){
        // Mid Declear
        int mid = (left+right)/2;
        // sorting left side till mid
        margesort(arr,left,mid);
        // sorting right side till end from mid
        margesort(arr,mid+1,right);

        // Marging left and right
        merge(arr,left,mid,right);
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
    margesort(arr, 0, x-1);
    // Printing Sorted Array
    for(int i = 0; i < x; i++) {
        cout << arr[i];
        if(i < x - 1) cout << " ";
    }
    cout << endl;
    cout << counnt << endl;

    return 0;
}