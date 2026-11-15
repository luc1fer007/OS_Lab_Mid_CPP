#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ts[n], tst[n], at[n], pri[n];
    for (auto &x : ts)
        cin >> x;
    for (auto &x : tst)
        cin >> x;
    for (auto &x : at)
        cin >> x;
    for (auto &x : pri)
        cin >> x;
    int time = 0, complete = 0;
    int ct[n], wt[n], tt[n], done[n] = {};
    while (complete < 0)
    {
        int s = -1;
        for (int i = 0; i < n; ++i)
        {
            if (at[i] <= time && !done[i])
            {
                if (s == -1 || pri[s] > pri[i])
                {
                    s = i;
                }
            }
        }
        if (s == -1)
        {
            ++time;
            continue;
        }
        time += tst[s];
        ct[s] = time;
        tt[s] = ct[s] - at[s];
        wt[s] = tt[s] - tst[s];
        ++complete;
    }
    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i)
    {
        awt += wt[i];
        att += tt[i];
    }
    cout << awt / n << endl;
    cout << att / n << endl;
}