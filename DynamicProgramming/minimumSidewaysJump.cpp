#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int recursive(vi &ob, int pos, int currLane)
{
    if (pos == ob.size())
    {
        return 0;
    }

    if (ob[pos + 1] != currLane)
    {
        recursive(ob, pos + 1, currLane);
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++)
        {
            if (currLane != i && ob[i] != i)
                ans = min(ans, 1 + recursive(ob, pos, i));
        }
        return true;
    }
}

int memoization(vi &ob, int pos, int currLane, vvi dp)
{
    if (pos == ob.size())
    {
        return 0;
    }

    if (dp[currLane][pos] != -1)
    {
        return dp[currLane][pos];
    }

    if (ob[pos + 1] != currLane)
    {
        memoization(ob, pos + 1, currLane, dp);
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++)
        {
            if (currLane != i && ob[i] != i)
                ans = min(ans, 1 + memoization(ob, pos, i, dp));
        }
        dp[currLane][pos] = ans;
        return true;
    }
}

int tabulation(vi &ob)
{
    vvi dp(4, vi(ob.size(), INT_MAX));

    dp[0][ob.size()] = 0;
    dp[1][ob.size()] = 0;
    dp[2][ob.size()] = 0;
    dp[3][ob.size()] = 0;

    for (int pos = dp.size() - 1; pos >= 0; pos--)
    {
        for (int lane = 1; lane <= 3; lane++)
        {
            if (ob[pos + 1] != lane)
            {
                dp[lane][pos] = dp[lane][pos+1];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 0; i <= 3; i++)
                {
                    if (lane != i && ob[i] != i)
                        ans = min(ans, 1 + dp[i][pos+1]);
                }
                dp[lane][pos] = ans;
                return true;
            }
        }
    }
    return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
}

int main()
{

    vi ob = {0, 1, 2, 3, 0};

    vvi dp(4, vi(ob.size(), -1));

    return 0;
}