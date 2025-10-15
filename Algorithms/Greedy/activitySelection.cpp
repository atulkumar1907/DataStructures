#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int maxMeetings(int st[], int en[], int n){
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        pair<int, int> p = make_pair(st[i], en[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 1;
    int ansEnd = v[0].second;

    for(int i=1; i<n; i++){
        if(v[i].first > ansEnd){
            ans++;
            ansEnd = v[i].second;
        }
    }
    return ans;
}

int main(){

    int st[] = {1, 3, 0, 5, 8, 5};
    int en[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    cout<<maxMeetings(st, en, n)<<endl;

    return 0;
}