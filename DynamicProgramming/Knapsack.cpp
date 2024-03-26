#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int recursive(int wt[], int val[], int index, int W)
{
    if (index == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (wt[index] < W)
    {
        include = val[index] + recursive(wt, val, index - 1, W - wt[index]);
    }
    int exclude = 0 + recursive(wt, val, index - 1, W);

    return max(include, exclude);
}

int topDown(int wt[], int val[], int index, int W, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][W] != -1)
    {
        return dp[index][W];
    }

    int include = 0;
    if (wt[index] < W)
    {
        include = val[index] + topDown(wt, val, index - 1, W - wt[index], dp);
    }
    int exclude = 0 + topDown(wt, val, index - 1, W, dp);

    dp[index][W] = max(include, exclude);

    return dp[index][W];
}

int bottomUp(int wt[], int val[], int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    for (int w = wt[0]; w < W; w++)
    {
        if (wt[0] <= W)
        {
            dp[0][w] = val[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int include = 0;
            if (wt[n] <= j)
            {
                include = val[i] + dp[i-1][j-wt[i]];
            }
            int exclude = 0 + dp[i-1][j];

            dp[n][j] = max(include, exclude);
        }
    }
    return dp[n-1][W];
}

int spaceOptimised(int wt[], int val[], int n, int W)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    for (int w = wt[0]; w < W; w++)
    {
        if (wt[0] <= W)
        {
            curr[w] = val[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int include = 0;
            if (wt[n] <= j)
            {
                include = val[n] + prev[j-wt[n]];
            }
            int exclude = 0 + prev[j];

            curr[j] = max(include, exclude);
        }
        prev = curr;
    }
        return prev[W];
}

int main()
{

    int n = 4;
    int wt[] = {1, 2, 4, 5};
    int val[] = {5, 4, 8, 6};
    int W = 5;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << recursive(wt, val, n - 1, 5) << endl;
    cout << topDown(wt, val, n - 1, 5, dp) << endl;
    cout<<bottomUp(wt, val, n-1, 5)<<endl;

    return 0;
}