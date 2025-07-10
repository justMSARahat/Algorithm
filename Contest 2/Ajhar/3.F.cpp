#include<iostream>
using namespace std;
int main(){

    int a;
    int b;
    cin>>a>>b;
    //user theke input a and b nibo. then ekta array creatre kornbo a size or.
    int box[a];
    // arrnay r modde input nibo shob element er jonnooo.
    int i = 0;
    while(i<a){
        cin>>box[i];
        i++;
    }
    int z = 0; // first ekti value dorte hoibe.
    int j = 0; // loop er jonno j variable dorte hobe.

    while(j<a-1){ // loop ta a-1 porjonto cholbe.
        int profit = box[j] - box[j+1] - b; // formula ta use korbo. 
        if(profit > z){ // jodi profit z theke boro hoi tahole.
            z = profit; // z er value profit er moto hoye jabe.
        }
        j++; // j er value increment hobe.
    }
    if(z < 0){ // jodi z er value 0 theke choto hoi tahole z er value 0 hoye jabe.
        z = 0;
    }
    cout<<z<<endl; // z er value print korbo.
    return 0; // program ta end hobe.











}