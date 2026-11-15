#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int task_serial[n], task_time[n], arrival_time[n];
    for (auto &x : task_serial)
        cin >> x;
    for (auto &x : task_time)
        cin >> x;
    for (auto &x : arrival_time)
        cin >> x;
    int remain_time[n], tran_time[n];
    for (int i = 0; i < n; ++i)
    {
        remain_time[i] = task_time[i];
    }
    int time = 0, complete = 0;
    while (complete < n)
    {
        int s = -1;
        for (int i = 0; i < n; ++i) 
        {
            if(arrival_time[i] <= time && remain_time[i] > 0)
            {
                if(s == -1 || remain_time[i] < remain_time[s])
                    s = i;
            }
        }
        if(s == -1) {
            ++time;
            continue;
        }
        if(--remain_time[s] == 0)
        {
            tran_time[s] = ++time - arrival_time[s];
            ++complete;
        }
        else
            ++time;
    }
    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << task_serial[i] << (i < n - 1 ? ", " : "\n");
        att += tran_time[i];
        awt += tran_time[i] - task_time[i];
    }
    cout << awt / n << endl
         << att / n << endl;
}