#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)


void heapify(vi &a, int n, int i){
    int maxIdx = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && a[l]>a[maxIdx]){
        maxIdx = l;
    }

    if(r<n && a[r]>a[maxIdx]){
        maxIdx = r;
    }

    if(maxIdx != i){
        swap(a[i], a[maxIdx]);

        heapify(a, n, maxIdx);
    }
}

void heapsort(vi &a){
    int n = a.size();

    for(int i= n/2-1; i>=0; i--){
        heapify(a, n, i);
    }

    for(int i=n-1; i>0; i--){
        swap(a[0], a[i]);

        heapify(a, i, 0);
    }
}


int main(){

    int n=6; //cin>>n;

    vi a(6); a = {10, 15, 21, 30, 18, 19};
    

    // rep(i, 0, n)
        // cin>>a[i];

    heapsort(a);

    rep(i, 0, n)
        cout<<a[i]<<" ";
    cout<<endl;

    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    priority_queue<int, vector<int>, greater<int>> pqa;
    pqa.push(2);
    pqa.push(3);
    pqa.push(1);
    cout<<pqa.top()<<endl;
    pqa.pop();
    cout<<pqa.top()<<endl;

    return 0;
}