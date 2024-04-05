#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int minimumRecursive(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
    {
        return 0;
    }
    int option1 = cost[0] + minimumRecursive(n, days, cost, index + 1);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = cost[1] + minimumRecursive(n, days, cost, i);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = cost[2] + minimumRecursive(n, days, cost, i);

    int ans = min(option1, min(option2, option3));

    return ans;
}

int memoization(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int option1 = cost[0] + memoization(n, days, cost, index + 1, dp);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = cost[1] + memoization(n, days, cost, i, dp);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = cost[2] + memoization(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));

    return dp[index];
}

int tabulation(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);

    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {

        int option1 = cost[0] + dp[k + 1];

        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int option2 = cost[1] + dp[i];

        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int minimum(int n, vector<int> &days, vector<int> &cost)
{

    int ans = 0;
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {
        while (month.size() >= 1 && month.front().first + 30 < day)
        {
            month.pop();
        }
        while (week.size() >= 1 && week.front().first + 30 < day)
        {
            week.pop();
        }

        month.push(make_pair(day, cost[1]));
        week.push(make_pair(day, cost[2]));
    }

    ans = min(ans+cost[0], min(month.front().second, week.front().second));

    return ans;
}

int main()
{

    int n = 2;
    vector<int> days = {2, 5};
    vector<int> costs = {1, 4, 25};

    cout << minimumRecursive(n, days, costs, 0) << endl;

    vector<int> dp(n + 1, -1);

    cout << memoization(n, days, costs, 0, dp) << endl;

    cout << tabulation(n, days, costs) << endl;

    return 0;
}