#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)

struct job{
    int id;
    int dead;
    int profit;
};

bool compare(job j1, job j2){
    return j1.profit > j2.profit;
}

vector<int> jobScheduling(job arr[], int n){
    sort(arr, arr+n, compare);

    int maxDeadline = INT_MIN;
    rep(i, 0, n){
        maxDeadline  = max(maxDeadline, arr[i].dead);
    }
;
    vector<int> schedule(maxDeadline+1, -1);

    int count =0;
    int maxProfit = 0;
    rep(i,0,n){
        int profit = arr[i].profit;
        int id = arr[i].id;
        int dead = arr[i].dead;

        for(int k=dead; k>=0; k--){
            if(schedule[k]==-1){
                count++;
                maxProfit += profit;
                schedule[k] = id;
                break;
            }
        }
    }

}

int main(){


    return 0;
}