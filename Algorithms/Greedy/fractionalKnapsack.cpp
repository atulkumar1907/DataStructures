#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

bool compare(pii p1, pii p2){
    double v1 = (double) p1.ff/p1.ss;
    double v2 = (double) p2.ff/p2.ss;

    return v1>v2;

}

signed main(){

//     5
// 21 7
// 24 4
// 12 6
// 40 5
// 30 6
// 20
    int n; cin>>n;

    vii a(n);

    rep(i, 0, n){
        cin>> a[i].ff>> a[i].ss;
    }

    int w; cin>>w;

    sort(a.begin(), a.end(), compare);

    int ans=0;
    rep(i,0,n){
        if(w>= a[i].ss){
            ans += a[i].ff;
            w -= a[i].ss;
            continue;
        }

        double vw = (double) a[i].ff/a[i].ss;
        ans += vw*w;
        w = 0;
        break;
    }

    cout<<ans<<endl;
}