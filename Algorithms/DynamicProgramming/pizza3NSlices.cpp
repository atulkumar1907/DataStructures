#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int revursive(int index, int endIndex, vi &slices, int n)
{
    if (n == 0 || index > endIndex)
    {
        return 0;
    }

    int take = slices[index] + revursive(index + 2, endIndex, slices, n - 1);
    int notTake = revursive(index + 1, endIndex, slices, n);

    return max(take, notTake);
}

int memoization(int index, int endIndex, vi &slices, int n, vvi &dp)
{
    if (n == 0 || index > endIndex)
    {
        return 0;
    }

    if (dp[index][n] != -1)
    {
        return dp[index][n];
    }

    int take = slices[index] + memoization(index + 2, endIndex, slices, n - 1, dp);
    int notTake = memoization(index + 1, endIndex, slices, n, dp);

    dp[index][n] = max(take, notTake);
}

int maxSizeSlices(vi slices)
{
    int k = slices.size();
    // int case1 = revursive(0, k-2, slices, k/3);
    // int case2 = revursive(1, k-1, slices, k/3);

    // return max(case1, case2);

    vvi dp1(k, vi(k, -1));
    int case1 = memoization(0, k - 2, slices, k / 3, dp1);
    vvi dp2(k, vi(k, -1));
    int case2 = memoization(1, k - 1, slices, k / 3, dp2);

    return max(case1, case2);
}

int tabulation(vi slices)
{
    int k = slices.size();

    vvi dp1(k+2, vi(k+2, 0));
    vvi dp2(k+2, vi(k+2, 0));

    for (int index = k - 2; k >= 0; k--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + dp1[index + 2][n - 1];
            int notTake = dp1[index + 1][n];

            dp1[index][n] = max(take, notTake);
        }
    }
    int case1 = dp1[0][k/3];
    for (int index = k - 1; k >= 1; k--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int take = slices[index] + dp2[index + 2][n - 1];
            int notTake = dp2[index + 1][n];

            dp2[index][n] = max(take, notTake);
        }
    }
    int case2 = dp2[1][k/3];

    return max(case1, case2);
}

int main()
{

    vi slices = {1, 2, 3, 4, 5, 6};

    cout << maxSizeSlices(slices) << endl;

    return 0;
}