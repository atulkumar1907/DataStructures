#include<bits/stdc++.h>
using namespace std;

pair<int, int> candyStore(int candies[], int n, int k){
    sort(candies, candies+n);

    int mini = 0;
    int buy = 0;
    int free = n-1;

    while(buy<=free){
        mini = mini + candies[buy];
        buy++;
        free -= k;
    }

    int maxi = 0;
    buy = n-1;
    free = 0;

    while(free<=buy){
        maxi += candies[buy];
        buy--;
        free += k;
    }
    return { mini, maxi };
}

int main(){

    int candies[] = {3, 2, 1, 4};
    int n = 4, k = 2;

    pair<int, int> ans = candyStore(candies, n, k);

    cout<<"Minimum amount: Rs."<<ans.first<<endl
    <<"Maximum amount: Rs."<<ans.second<<endl;

    return 0;
}