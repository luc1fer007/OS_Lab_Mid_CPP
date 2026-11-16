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

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    
    int process[n],burst[n],arrival[n]={0};
    int remaining[n],completion[n],waiting[n],turn[n];

    for(int i=0;i<n;i++) cin >> process[i];
    for(int i=0;i<n;i++) {cin >> burst[i] ; remaining[i]=burst[i];}
    //for(int i=0;i<n;i++) cin >> arrival[i];

    int tq;
    cin >> tq;

    int time = 0, complete = 0;

    while(complete < n){

        int flag = 0;

        for(int i=0;i<n;i++){
            if(arrival[i] <= time && remaining[i] > 0){

                flag = 1;

                if(remaining[i] > tq){
                    remaining[i] -= tq;
                    time += tq;
                }
                else{
                    time += remaining[i];
                    remaining[i] = 0;

                    completion[i] = time;
                    complete++;
                }
            }
        }

        if(flag == 0){
            time++;
        }
    }

    float totalt =0,totalw=0;

    for(int i=0;i<n;i++){
        turn[i] = completion[i] - arrival[i];
        waiting[i] = turn[i] - burst[i];

        totalt+=turn[i];
        totalw+=waiting[i];
    }


    cout << "process\tburst\tarrival\twaiting\tturn\n";

    for(int i=0;i<n;i++){
        cout << process[i] << "\t" << burst[i]  << "\t"<< arrival[i] << "\t" << waiting[i] << "\t" << turn[i] << endl;
    }cout << endl;


    cout << totalt/n << endl;
    cout << totalw/n << endl;

    return 0;
}
