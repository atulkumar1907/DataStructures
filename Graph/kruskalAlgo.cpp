#include<bits/stdc++.h>
using namespace std;

bool compareEdge(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node]==node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u  = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v]<rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
    
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj;

    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++){
            cin>>adj[i][j];
        } 
    }

    sort(adj.begin(), adj.end(), compareEdge);

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);
    int minweight = 0;

    for(int i=0; i<m; i++){
        int u = findParent(parent, adj[i][0]);
        int v = findParent(parent, adj[i][1]);
        int wt = adj[i][2];

        if(u!=v){
            minweight += wt;
            unionSet(u, v, parent, rank);
        }
    }


    return minweight;
}