#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &num, int n){
    if(n<0) return 0;

    if(n==0) return num[0];

    int incl = maxSum(num, n-2) + num[n];

    int excl = maxSum(num, n-1);

    return max(incl, excl);
}

int topDown(vector<int> &num, int n, vector<int> &dp){
    if(n<0) return 0;

    if(n==0) return num[0];

    if(dp[n]!=-1) return dp[n];

    int incl = topDown(num, n-2, dp) + num[n];

    int excl = topDown(num, n-1, dp);

    dp[n] =  max(incl, excl);
    return dp[n];
}

int bottomDown(vector<int> &num){
    int n = num.size();
    vector<int> dp(n, 0);
    
    dp[0] = num[0];

    for(int i=1; i<n; i++){
        dp[i] = max(num[i] + dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

int spaceOptimized(vector<int> &num, int n){
    int prev2 = 0;
    int prev1 = num[0];

    for(int i=1; i<n; i++){
        int curr = max(num[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    } 

    return prev1;
}

int main(){

    vector<int> num = {9, 9, 8, 2};
    int n = 4;

    cout<<maxSum(num, n)<<endl;

    vector<int> dp(n, -1);
    cout<<topDown(num, n-1, dp)<<endl;

    cout<<bottomDown(num)<<endl;

    cout<<spaceOptimized(num, n)<<endl;

    return 0;
}