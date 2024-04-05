#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int recursive(vector<int> &arr, int curr, int prev)
{
    int n = arr.size();
    if (curr == n)
        return 0;

    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        include = 1 + recursive(arr, curr + 1, curr);
    }
    int exclude = recursive(arr, curr, prev);

    return max(include, exclude);
}

int memoization(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp)
{
    int n = arr.size();
    if (curr == n)
        return 0;

    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev];
    }

    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        include = 1 + memoization(arr, curr + 1, curr, dp);
    }
    int exclude = memoization(arr, curr, prev, dp);

    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

int tabulation(vector<int> &arr)
{
    vector<vector<int>> dp(5+1, vector<int>(5 + 1, -1));
    int n = arr.size();

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = n - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                include = 1 + dp[curr + 1][curr+1];
            }
            int exclude = dp[curr][prev+1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int optimization(vector<int> &arr)
{
    vector<vector<int>> dp(5+1, vector<int>(5 + 1, -1));
    int n = arr.size();
    vector<int> currRow(n+1, 0);
    vector<int> next(n+1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = n - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                include = 1 + next[curr+1];
            }
            int exclude = next[prev+1];

            currRow[prev + 1] = max(include, exclude);
        }
        next = currRow;
    }

    return next[0];
}

int binarySearch(vector<int> arr, int n){
    if(n==0){
        return 0;
    }
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<n; i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int index = lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
            ans[index] = ans[i];
        }
    }
    return ans.size();
}

int main()
{

    vector<int> arr = {5, 8, 3, 9, 1};
    // cout << recursive(arr, 0, -1) << endl;

    // vector<vector<int>> dp(5, vector<int>(5 + 1, -1));

    // cout << memoization(arr, 0, -1, dp) << endl;

    // cout<<tabulation(arr)<<endl;

    cout<<binarySearch(arr, 5)<<endl;

    return 0;
}