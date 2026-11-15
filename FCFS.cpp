#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int task_serial[n], task_time[n];
    for(auto &x : task_serial)
        cin >> x;
    for(auto &x : task_time)
        cin >> x;
    int wait_time[n], tran_time[n];
    wait_time[0] = 0;
    for (int i = 1; i < n; ++i)
        wait_time[i] = wait_time[i - 1] + task_time[i - 1];
    for (int i = 0; i < n;++i)
        tran_time[i] = wait_time[i] + task_time[i];
    double awt = 0, att = 0;
    for (int i = 0; i < n; ++i){
        awt += wait_time[i];
        att += tran_time[i];
    }
    cout << awt / n << endl;
    cout << att / n << endl;
}