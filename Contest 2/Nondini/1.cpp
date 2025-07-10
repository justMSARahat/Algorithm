#include<bits/stdc++.h>
using namespace std;

struct StartEndTime{
    int begin;
    int finish;
};
bool sorting(StartEndTime m, StartEndTime n){
    return m.finish < n.finish; // end time er upor sort korchi
}

int main(){
    int times;
    cin>>times; // eta test case run korar jonno
    while(times--){ // test case run
        int numberofwork; cin>>numberofwork; // number of work input nichi
        StartEndTime work[numberofwork]; // array of structure use korechi shob event er start and end time rakhte
        int i = 0;
        while(i<numberofwork){ // shob event er start and end time input nichi
            cin>>work[i].begin>>work[i].finish;
            i++;
        }
        int count = 1; // first event ta to nite hobe
        // event gulo ke end time er upor sort korechi
        sort(work, work + numberofwork, sorting);

        int firstEndTime = work[0].finish; // first event er end time ta
        int j = 1; // next event er jonno
        while(j<numberofwork){ // shob event check korchi
            if(work[j].begin >= firstEndTime){ // jodi current event er start time
                count++; // count barabo
                firstEndTime = work[j].finish; // current event er end time ta default end time hisebe nibo
            }
            j++; // next event e jabo
        }
        cout << count << endl; // shob event er jonno maximum event count ta print korbo
    }
    return 0; // program sesh
}
