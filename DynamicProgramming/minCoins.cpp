#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int> &num, int x){
    if(x==0){
        return 0;
    }
    if(x<0){
        return -1;
    }
    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = recursive(num, x-num[i]);
        if(ans!=-1){
            mini = min(ans+1, mini);
        }
    }
    return mini;
}

int topDown(vector<int> &num, int x, vector<int> &dp){
    if(x==0){
        return 0;
    }
    if(x<0){
        return -1;
    }

    if(dp[x]!=-1) return dp[x];

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = topDown(num, x-num[i], dp);
        if(ans!=-1){
            mini = min(ans+1, mini);
        }
    }
    dp[x] = mini;
    return mini;
}

int bottomUp(vector<int> &num, int x){
    vector<int> dp(x+1, INT_MAX);

    dp[0] = 0;

    for(int i=1; i<=x; i++){
        for(int j=0; j<num.size(); j++){
           if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
             dp[i] = min(dp[i], 1+dp[i-num[j]]);
           }
        }
    }

    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}

int main(){
    int target = 11;
    vector<int> num = {1, 2, 5};

    cout<<recursive(num, target)<<endl;

    vector<int> dp(target+1, -1);
    int ans = topDown(num, target, dp);
    cout<<ans<<endl;

    cout<<bottomUp(num, target)<<endl;


    return 0;
}