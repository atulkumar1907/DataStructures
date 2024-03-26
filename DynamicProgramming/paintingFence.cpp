#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

int recursive(int n, int k){

    if(n==1){
        return k;
    }

    if(n==2){
        return (k+(k*(k-1)));
    }

    return (k-1)*(recursive(n-1, k)+recursive(n-2, k));
}

int topDown(int n, int k, vector<int> &dp){
    if(n==1){
        return k;
    }

    if(n==2){
        return (k+(k*(k-1)));
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = (k-1)*(recursive(n-1, k)+recursive(n-2, k));

    return dp[n];
}

int bottomUp(int n, int k){
    vector<int> dp(n+1, -1);

    dp[1] = k;
    dp[2] = k+ k*(k-1);

    for(int i=3; i<=n; i++){
        dp[i] = (k-1)*(dp[i-1]+dp[i-2]);
    }

    return dp[n];
}


int main(){

    int n = 3, k = 2;

    cout<<recursive(n, k)<<endl;

    vector<int> dp(n+1, -1);
    cout<<topDown(n, k, dp)<<endl;

    cout<<bottomUp(n, k);

    return 0;
}