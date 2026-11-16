/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, tq;
    cin >> n;
    int p[n], bt[n], at[n], tt[n], wt[n], ct[n], rem[n], time = 0, complete = 0;
    for (auto &x : p)
        cin >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> bt[i];
        rem[i] = bt[i];
    }
    for (auto &x : at)
        cin >> x;
    cin >> tq;
    queue<int> q;
    bool added[n] = {false};
    while (complete < n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (at[i] <= time && !added[i] && rem[i] > 0)
            {
                q.push(i);
                added[i] = true;
            }
        }
        if (q.empty())
        {
            ++time;
            continue;
        }
        int s = q.front();
        q.pop();
        int exe = min(tq, rem[s]);
        rem[s] -= exe;
        time += exe;
        for (int i = 0; i < n; ++i)
        {
            if (at[i] <= time && !added[i] && rem[i] > 0)
            {
                q.push(i);
                added[i] = true;
            }
        }
        if (rem[s] > 0)
            q.push(s);
        else
        {
            ct[s] = time;
            tt[s] = ct[s] - at[s];
            wt[s] = tt[s] - bt[s];
            ++complete;
        }
    }
    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i)
    {
        att += tt[i];
        awt += wt[i];
    }
    cout << att / n << endl;
    cout << awt / n << endl;
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, tq;
    cin >> n;
    int p[n], bt[n], at[n], tt[n], wt[n], ct[n], rem[n], time = 0, complete = 0;
    for (auto &x : p)
        cin >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> bt[i];
        rem[i] = bt[i];
    }
    for (auto &x : at)
        cin >> x;
    cin >> tq;
    queue<int> q;
    bool added[n] = {false};
    while (complete < n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (at[i] <= time && !added[i] && rem[i] > 0)
            {
                q.push(i);
                added[i] = true;
            }
        }
        if (q.empty())
        {
            ++time;
            continue;
        }
        int s = q.front();
        q.pop();
        int exe = min(tq, rem[s]);
        rem[s] -= exe;
        time += exe;
        for (int i = 0; i < n; ++i)
        {
            if (at[i] <= time && !added[i] && rem[i] > 0)
            {
                q.push(i);
                added[i] = true;
            }
        }
        if (rem[s] > 0)
            q.push(s);
        else
        {
            ct[s] = time;
            tt[s] = ct[s] - at[s];
            wt[s] = tt[s] - bt[s];
            ++complete;
        }
    }
    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i)
    {
        att += tt[i];
        awt += wt[i];
    }
    cout << att / n << endl;
    cout << awt / n << endl;
    return 0;
}
