#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int recursive(vector<vector<int>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    int right = recursive(mat, i, j + 1, maxi);
    int diagonal = recursive(mat, i + 1, j + 1, maxi);
    int down = recursive(mat, i + 1, j, maxi);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int memoization(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int diagonal = memoization(mat, i + 1, j + 1, maxi, dp);
    int down = memoization(mat, i + 1, j, maxi, dp);
    int right = memoization(mat, i, j + 1, maxi, dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return 0;
    }
}

int tabulatioin(vector<vector<int>> &mat, int & maxi)
{
    vector<vector<int>> dp(mat.size()+1, vector<int>(mat[0].size()+1, 0));

    dp[mat.size() - 1][mat[0].size() - 1] = 0;

    for (int i = mat.size() - 1; i >= 0; i--)
    {
        for (int j = mat[0].size() - 1; j >= 0; j--)
        {
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];
            int right = dp[i][j + 1];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}


int space(vector<vector<int>> &mat, int & maxi)
{
    vector<vector<int>> dp(mat.size()+1, vector<int>(mat[0].size()+1, 0));
    vector<int> curr (mat[0].size()+1, 0);
    vector<int> next (mat[0].size()+1, 0);

    dp[mat.size() - 1][mat[0].size() - 1] = 0;

    for (int i = mat.size() - 1; i >= 0; i--)
    {
        for (int j = mat[0].size() - 1; j >= 0; j--)
        {
            int diagonal = next[j + 1];
            int down = next[j];
            int right = curr[j + 1];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return curr[0];
}

int main()
{

    int n = 2, m = 2;
    int maxi = 0;
    vector<vector<int>> mat = {{1, 1}, {1, 1}};

    recursive(mat, 0, 0, maxi);
    cout << maxi << endl;
    maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    memoization(mat, 0, 0, maxi, dp);
    cout << maxi << endl;
    maxi = 0;
    tabulatioin(mat, maxi);
    cout<<maxi<<endl;

    return 0;
}