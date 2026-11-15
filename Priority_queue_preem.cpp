
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int task_serial[n], task_time[n], arrival_time[n], priority[n];
    for (auto &x : task_serial)
        cin >> x;
    for (auto &x : task_time)
        cin >> x;
    for (auto &x : arrival_time)
        cin >> x;
    for (auto &x : priority)
        cin >> x;

    int remain_time[n], ct[n], wt[n], tt[n];
    for (int i = 0; i < n; ++i)
        remain_time[i] = task_time[i];

    int time = 0, complete = 0;
    while (complete < n)
    {
        int s = -1;
        for (int i = 0; i < n; ++i)
            if (arrival_time[i] <= time && remain_time[i] > 0)
                if (s == -1 || priority[i] < priority[s])
                    s = i;

        if (s == -1)
        {
            ++time;
            continue;
        }

        --remain_time[s];
        ++time;
        if (remain_time[s] == 0)
        {
            ct[s] = time;
            tt[s] = ct[s] - arrival_time[s];
            wt[s] = tt[s] - task_time[s];
            ++complete;
        }
    }

    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << task_serial[i] << (i < n - 1 ? ", " : "\n");
        awt += wt[i];
        att += tt[i];
    }
    cout << "AVG WT : " << awt / n << endl;
    cout << "AVG TT : " << att / n << endl;
}
