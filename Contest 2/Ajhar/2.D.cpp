#include<iostream>
using namespace std;

//fuctin craete korechi eligible student count korar jonno.
void participation(int a, int b, int x) {
    // a = minimum std, b = participation, x = eligible std count.
    for (int i = 0; i < a; i++) { // loop use kore student count korbo.
        int totalpart; cin>>totalpart; // student koto bar participate korece ta input nibo.
        // user theke input nibo.
        if (5-totalpart >= b) { // condition check korbo jodi true hoi taile vitore jabe.
            x++; // eligible student count korbo.
        }
    }
    cout << x / 3 << endl; // 3 person e 1 team hbe, tai x/3 kore print korbo.


}



int main(){
    int a; // minimum std;
    int b; // participation
    cin>>a>>b; // user theke input a and b nibo.
    int x = 0; // eligible std cnt korar jonno.
    participation(a,b,x); // function call.








}