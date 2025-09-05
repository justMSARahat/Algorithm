#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int list[n], lis[n];

    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
        lis[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[i] > list[j])
            {
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(max<lis[i]){
            max = lis[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<lis[i]<<" ";
    }
    cout<<endl<<"LIS -> "<<max;
}