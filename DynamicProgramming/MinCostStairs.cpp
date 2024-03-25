#include<bits/stdc++.h>
using namespace std;

int recursive(int n, vector<int> &cost){
    if(n==1 || n==0) return cost[n];

    return cost[n] + min(recursive(n-1, cost), recursive(n-2, cost));
}

int topDown(int n, vector<int> &cost, vector<int> &dp){
    if(n==1 || n==0) return cost[n];

    if(dp[n]!=-1) return dp[n];

    dp[n] = cost[n] + min(topDown(n-1, cost, dp), topDown(n-2, cost, dp));

    return dp[n];
}

int bottomUp(int n, vector<int> &cost){
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

int lessSpace(int n, vector<int> &cost){
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i=2; i<n; i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);

}

int main(){
    int n = 3;
    vector<int> cost(n);
    cost = {10, 15, 20};
    cout<<"N: "<<n<<endl;

    cout<<"Recursive: "<<min(recursive(n-1, cost), recursive(n-2, cost))<<endl;

    vector<int> dp(n+1, -1);
    cout<<"Memoization: "<<min(topDown(n-1, cost, dp), topDown(n-2, cost, dp))<<endl;

    cout<<"Tabulation: "<<bottomUp(n, cost)<<endl;

    cout<<"Space Optimised: "<<lessSpace(n, cost)<<endl;
}
