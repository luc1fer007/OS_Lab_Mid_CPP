#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ts[n], tst[n], pri[n];
    for (auto &x : ts)
        cin >> x;
    for (auto &x : tst)
        cin >> x;
    for (auto &x : pri)
        cin >> x;

    int time = 0, complete = 0;
    int ct[n], wt[n], tt[n], done[n] = {};

    while (complete < n)
    {
        int s = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!done[i])
            {
                if (s == -1 || pri[s] > pri[i])
                {
                    s = i;
                }
            }
        }

        time += tst[s];
        ct[s] = time;
        tt[s] = ct[s];
        wt[s] = tt[s] - tst[s];
        done[s] = 1;
        ++complete;
    }

    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << ts[i] << (i < n - 1 ? ", " : "\n");
        awt += wt[i];
        att += tt[i];
    }
    cout << "AVG WT : " << awt / n << endl;
    cout << "AVG TT : " << att / n << endl;
}
