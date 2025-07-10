#include<bits/stdc++.h>
using namespace std;

// Crating Function
void maxProfitCount(int numberOfDays, int rentCosts, int honey[]){

    // for comparing maximum profit we create a variable and will compare and store value time by time
    int maximumProfit = 0;


    //variable for loop
    int i = 0;
    // loop calculating max profit by comparing with maximumProfit
    while( i<numberOfDays-1){
        if(honey[i] - honey[i+1] - rentCosts > maximumProfit){
            // changing maximum Profit value with new Value
            maximumProfit = honey[i]-honey[i+1]-rentCosts;
        }
            i++;
    }

    cout<<maximumProfit<<endl;

}

int main(){
    // Variable to store data
    int numberOfDays;
    int rentCosts;
    cin>>numberOfDays >> rentCosts;
    // array to store individual barel of honey info
    int honey[numberOfDays];


    // Input and Store the value for the data types above
    for(int i = 0; i < numberOfDays; i++){
        cin>>honey[i];
    }

    // calling the function to calculate profit
    maxProfitCount(numberOfDays, rentCosts, honey);


    return 0;
}