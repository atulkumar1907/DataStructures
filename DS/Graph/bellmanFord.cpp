#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"Enter no. of nodes and Edges: ";
    int n, m;
    cin >> n >> m;

    unordered_map<int, pair<int, int>> adj;

    for(int i=0; i<m; i++){
        int u, v, w;

        adj[u] = (make_pair(v, w));
       
    }

    vector<int> dis(n+1, 1e9);
    int src = 1;
    int dest = 3;
    dis[src] = 0;

    // n-1 times
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int u = j;
            int v = adj[j].first;
            int wt = adj[j].second;

            if((dis[u] != 1e9) && (dis[u] + wt < dis[v])){
                dis[v] = dis[u] + wt;
            }
        }
    }

    // checkk for -ve cycle
    bool flag = 0;
    for(int j=0; j<m; j++){
            int u = j;
            int v = adj[j].first;
            int wt = adj[j].second;

            if((dis[u] != 1e9) && (dis[u] + wt < dis[v])){
                flag = 1;
            }
        }

    if(flag==0){
        return dis[dest];
    }


    return 0;
}