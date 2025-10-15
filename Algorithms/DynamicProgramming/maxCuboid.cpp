#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

bool check(vector<int> base, vector<int> newBox){
    if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2] ){
        return true;
    }
    return false;
}


int optimization(vector<vector<int>> &arr)
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
            if (prev == -1 || check(arr[curr], arr[prev]))
            {
                include = arr[curr][2] + next[curr+1];
            }
            int exclude = next[prev+1];

            currRow[prev + 1] = max(include, exclude);
        }
        next = currRow;
    }

    return next[0];
}

int maxHeight(vector<vector<int>> &cuboids){
    for(auto &a : cuboids){
        sort(a.begin(), a.end());
    }
    sort(cuboids.begin(), cuboids.end());

    return optimization(cuboids);
}


int main(){

    return 0;
}