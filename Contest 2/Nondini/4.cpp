#include<bits/stdc++.h>
using namespace std;

int main(){
    int number;
    int part;
    cin >> number >> part; // input nicci number and participation.

    int tried; // ekta student koto bar attempt niche ta store korar jonno
    int x = 0; // eligible student count korar jonno
    int i = 0; // loop er jonno
    while(i<number){
        cin>>tried; // student er attempt input nite hobe
        int condition = 5 - part; // condition set kora hocche, jekhane 5 holo total participation er limit
        if(tried <= condition){ // jodi student er attempt condition er cheye kom hoy
            x++; // tahole eligible student er count barano hobe
        }
        i++; // loop er next iteration e jete hobe
    }
    cout << x/3 << endl; // eligible student er count ke 3 diye vag kore print kora hobe, karon 3 jon er group banano hobe
    return 0; // program er shesh

}