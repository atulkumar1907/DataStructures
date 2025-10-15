#include<bits/stdc++.h>
using namespace std;

int recursive(int n){
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }
    return (n-1)*(recursive(n-1) + recursive(n-2));
}

int topDown(int n, vector<int> &dp){
     if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    if(dp[n]!=-1) return dp[n];
    dp[n] = (n-1)*(recursive(n-1) + recursive(n-2));

    return dp[n];

}

int bottomUp(int n){
    vector<int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }

    return dp[n];
}

int spaceOptimised(int n){
    int prev2 = 0;
    int prev1 = 1;

    for(int i=3; i<=n; i++){
        int curr = (i-1)* (prev1 + prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n = 5;

    cout<<recursive(n)<<endl;

    vector<int> dp(n+1, -1);
    cout<<topDown(n, dp)<<endl;

    cout<<bottomUp(n)<<endl;

    cout<<spaceOptimised(n)<<endl;
    return 0;
}