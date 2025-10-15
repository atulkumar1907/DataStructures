#include<bits/stdc++.h>
using namespace std;

int surviveIsland(int n, int s, int m){

    int sunday = s/7;

    int buyingDays = s-sunday;
    int ans = 0;

    if((s*m)%n==0){
        ans = (s*m)/n;
    }
    else{
        ans =  (s*m)/n+1;
    }

    if(ans<=buyingDays){
        return ans;
    }
    return -1;
}

int main(){

    int n = 16, s = 10, m = 2;

    cout<<surviveIsland(n, s, m);

    return 0;
}