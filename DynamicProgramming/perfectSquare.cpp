#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)


int recursive(int n){
    if(n==0){
        return 0;
    }
    int ans=n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans, 1+recursive(n-i*i));
    }
    return ans;
}

int memoization(int n, vector<int>& dp){
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans, 1+memoization(n-i*i, dp));
    }
    dp[n] = ans;

    return dp[n];
}
int tabulation(int n){
    vector<int>dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int j=1; j<=n; j++){
        for(int i=1; i*i<=n; i++){
       if(j-i*i>=0){
         dp[j] = min(dp[j], 1+dp[j-i*i]);
       }
    }
    }

    return dp[n];
}

int main(){
    int n = 5;

    cout<<recursive(n)<<endl;

    vector<int> dp(n+1, -1);

    cout<<memoization(n, dp)<<endl;

    cout<<tabulation(n)<<endl;

    return 0;
}