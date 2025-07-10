#include<bits/stdc++.h>
using namespace std;

int main(){
    int x; // total koto bar colbe
    cin>>x; // x er value input nibo
    while(x--){ // x er number er upore while loop cholbe
        string input; // string theke number ber korar jonno input nibo
        cin>>input;
        int longs = input.length(); // string er length ber korbo for loop er jonno
        string result = ""; // output jei string ta hobe ta store korar jonno arekta string nibo

        int i = 0;
        while( i<longs ){ // loop use kore input string er prottek character er jonno cholbe
            int number = 1; // number er value 1 theke suru hobe
            int j = i+1; // j er value i er por theke suru hobe, j er value i+1 theke suru hobe
            while(j<longs && input[i] == input[j]){ // j er value i er por theke suru hobe, j er value i+1 theke suru hobe. j er value i er value er shathe mile jodi thake
                number++; // number er value increment hobe
                j++;

            }
            result += to_string(number) + input[i]; // result string e number er value and i er value add hobe
            i = j; // i er value increment hobe
        }
        cout << result << endl; // result string ta print hobe
    }
    return 0; // program er end
}