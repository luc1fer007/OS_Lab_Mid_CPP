//non piority
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int process[n],burst[n],priority[n];

    for(int i=0;i<n;i++) cin >> process[i];
    for(int i=0;i<n;i++) cin >> burst[i];
    for(int i=0;i<n;i++) cin >> priority[i];

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(priority[i] > priority[j]){
                swap(process[i],process[j]);
                swap(burst[i],burst[j]);
                swap(priority[i],priority[j]);
            }
        }
    }

    int wait[n],turn[n];
    wait[0] = 0;

    for(int i=1;i<n;i++)wait[i] = wait[i-1]+burst[i-1];

    for(int i=0;i<n;i++)turn[i] = wait[i]+burst[i];


    float totalw=0,totalt=0;

    for(int i=0;i<n;i++){
        totalt+=turn[i];
        totalw+=wait[i];
    }

     cout << "process\tbrust\tpiority\twaiting\tturn\n";

    for(int i=0;i<n;i++){
        cout << process[i] << "\t" << burst[i] << "\t" << priority[i] << "\t" << wait[i] << "\t" << turn[i] << endl;
    }cout << endl;

    cout << totalt/n << endl;
    cout << totalw/n;

    return 0;
}
