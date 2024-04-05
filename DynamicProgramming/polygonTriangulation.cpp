#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int recursive(vector<int> &v, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, (v[i] * v[j] * v[k] + recursive(v, i, k) + recursive(v, k, j)));
    }
    return ans;
}

int memoization(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, (v[i] * v[j] * v[k] + memoization(v, i, k, dp) + memoization(v, k, j, dp)));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int tabulation(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, (v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

int main()
{

    int n = 3;
    vector<int> v = {1, 2, 3};
    cout << recursive(v, 0, n - 1) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << memoization(v, 0, n - 1, dp) << endl;

    cout<<tabulation(v)<<endl;

    return 0;
}