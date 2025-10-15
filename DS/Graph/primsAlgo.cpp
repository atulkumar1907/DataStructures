#include<bits/stdc++.h>
using namespace std;

int main(){
     int n, m;
    cin>>n>>m;

    unordered_map<int, list<pair<int, int> > > adj;

    for(int i=0; i<m; i++){
        int u, v, w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    key[1] = 0;
    parent[1] = -1;

    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;
        for(int v=1; v<=n; v++){
            if(mst[v]==false && key[v] <mini){
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for(auto i: adj[u]){
            int v = i.first;
            int w = i.second;

            if(mst[v] ==false && w<key[v]){
                parent[v] = u;
                key[u] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> res;
    for(int i=2; i<=n; i++){
        res.push_back({{parent[i], i}, key[i]});
    }


    return 0;
}