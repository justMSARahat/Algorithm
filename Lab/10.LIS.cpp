#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int List[n];
    for (int i = 0; i < n; i++)
    {
        cin >> List[i];
    }

    int LIS[n], Track[n];
    memset(Track, -1, sizeof(Track));
    for (int i = 0; i < n; i++)
    {
        LIS[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (List[j] < List[i])
            {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
                if (LIS[i] == 1 + LIS[j])
                {
                    Track[i] = j;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << LIS[i] << " ";
    }
    cout << endl;

    int mx = INT_MIN, ind;
    for (int i = 0; i < n; i++)
    {
        if (mx < LIS[i])
        {
            mx = LIS[i];
            ind = i;
        }
    }
    cout << "LIS Length = " << mx << endl;

    for (int i = 0; i < n; i++)
    {
        cout << Track[i] << " ";
    }
    cout << endl;
    vector<int> ans;
    for (int i = ind; i >= 0;)
    {
        ans.push_back(List[i]);
        i = Track[i];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}