#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

int recursive(vector<int> sat, int index, int time){
    if(index==sat.size()){
        return 0;
    }
    int include = (time+1)* sat[index] + recursive(sat, index+1, time+1);
    int exclude = recursive(sat, index+1, time);

    int ans = max(include, exclude);
    return ans;
}

int memoization(vector<int> sat, int index, int time, vector<vector<int>> &dp){
    if(index==sat.size()){
        return 0;
    }
    if(dp[index][time]!=-1){
        return dp[index][time];
    }
    int include = (time+1)* sat[index] + memoization(sat, index+1, time+1, dp);
    int exclude = memoization(sat, index+1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

int tabulation(vector<int> sat){
    int n = sat.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int index=n-1; index>=0; index--){
        for(int time = n-1; time>=0; time--){
            int include = (time+1)* sat[index] + dp[index+1][time+1];
            int exclude = dp[index+1][time];

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int optimization(vector<int> sat){
    int n = sat.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int index=n-1; index>=0; index--){
        for(int time = n-1; time>=0; time--){
            int include = (time+1)* sat[index] + next[time+1];
            int exclude = next[time];

            curr[time] = max(include, exclude);
        }
        next = curr;
    }

    return curr[0];
}

int optimization2(vector<int> sat){
    int n = sat.size();

    int nextRowNextCol = 0;
    int NextRowSameCol = 0;
    int curr = 0;

    for(int index=n-1; index>=0; index--){
        for(int time = n-1; time>=0; time--){
            int include = (time+1)* sat[index] + nextRowNextCol;
            int exclude = NextRowSameCol;

            curr = max(include, exclude);
        }
    }

    return nextRowNextCol;
}


int main(){

    vector<int> sat = {-1, -8, 0, 5, -9};
    sort(sat.begin(), sat.end());
    int n = sat.size();
    cout<<recursive(sat, 0, 0)<<endl;

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout<<memoization(sat, 0, 0, dp)<<endl;

    cout<<tabulation(sat)<<endl;

    cout<<optimization(sat)<<endl;

    cout<<optimization2(sat)<<endl;

    return 0;
}