#include<bits/stdc++.h>

using namespace std;

vector<int> shortestPathBFS(unordered_map<int, list<int>> &adj, int s, int t, 
                            unordered_map<int, bool> &visited, unordered_map<int, int> &parent){
    
     queue<int> q;
     q.push(s);
     visited[s] = 1;
     parent[s] = -1;

     while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
     }

    vector<int> ans;
    int curr = t;
    ans.push_back(t);
    while(curr != s){
        curr = parent[curr];
        ans.push_back(curr);
    }
    return ans;
}

int main(){

     int n, m;
    cin>>n>>m;

    unordered_map<int, list<int>> adj;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
    }

     unordered_map<int, bool> visited;
     unordered_map<int, int> parent;


     
}