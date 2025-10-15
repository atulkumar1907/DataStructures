#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

int findWaysRecursive(vector<int> &num, int target){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }
    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += findWaysRecursive(num, target-num[i]);
    }

    return ans;
}

int memoization(vector<int> &num, int target, vector<int> &dp){
    if(target==0){
        return 1;
    }
    if(target<0){
        return 0;
    }

    if(dp[target]!=-1){
        return dp[target];
    }
    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += memoization(num, target-num[i], dp);
    }

    dp[target] = ans;
    return dp[target];
}

int tabulation(vector<int> &num, int target){
    vector<int> dp(target+1, 0);

    dp[0] = 1;

    for(int i=1; i<=target; i++){
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0){
                dp[i] += dp[i-num[j]];
            }
        }
    }
    return dp[target];
}



int main(){
    int n = 3;
    vector<int>num = {1, 2, 5}; 
    int target = 5;

    cout<<findWaysRecursive(num, target)<<endl;

    vector<int> dp(target+1, -1);
    cout<<memoization(num, target, dp)<<endl;
    cout<<tabulation(num, target)<<endl;
    return 0;
}