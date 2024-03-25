#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z){
    if(n==0) return 0;

    if(n<0) return INT_MIN;

    int a = solve(n-x, x, y, z)+1;
    int b = solve(n-y, x, y, z)+1;
    int c = solve(n-z, x, y, z)+1;

    return max(a, max(b, c));
}

int topDown(int n, int x, int y, int z, vector<int> &dp){
    if(n==0) return 0;

    if(n<0) return INT_MIN;

    if(dp[n]!=-1) return dp[n];

    int a = topDown(n-x, x, y, z, dp)+1;
    int b = topDown(n-y, x, y, z, dp)+1;
    int c = topDown(n-z, x, y, z, dp)+1;

    dp[n] = max(a, max(b, c));

    return dp[n];
}

int bottomUp(int n, int x, int y, int z){
    vector<int> dp(n+1, INT_MIN);

    dp[0] = 0;

    for(int i=1; i<=n; i++){
        if(i-x>=0){
            dp[i] = max(dp[i], dp[i-x]+1);
        }
        if(i-y>=0){
            dp[i] = max(dp[i], dp[i-y]+1);
        }
        if(i-z>=0){
            dp[i] = max(dp[i], dp[i-z]+1);
        }
    }

    if(dp[n]<0){
        return 0;
    }
    return dp[n];
}



int main(){

    int n=7, x=5, y=2, z=2;

    cout<<solve(n, x, y, z)<<endl;

    vector<int> dp(n+1, -1);
    cout<<topDown(n, x, y, z, dp)<<endl;

    cout<<bottomUp(n, x, y, z)<<endl;
    return 0;
}