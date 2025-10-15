#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

bool isCycleBFS(int src,  unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited){
     unordered_map<int, int> parent;

     visited[src] = 1;
     parent[src] = -1;

     queue<int> q;
     q.push(src);

     while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto neighbour: adj[curr]){
            if(visited[neighbour]==true && neighbour !=parent[curr]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = curr;
            }
        }
     }

    return false;
}


bool isCycleDFS(int node, int parent, unordered_map<int, list<int>> &adj,  unordered_map<int, bool> &visited){
    visited[node] = 1;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]==true && neighbour!=parent){
            bool cycle = isCycleDFS(neighbour, node, adj, visited);
            if(cycle) return true;
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}


int main(){

    int n,m; cin>>n>>m;

    unordered_map<int, list<int>> adj;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(auto i: adj){
        cout<<i.first<<"->";;
        for(auto &j: i.second){
            cout<<j<<" ";  
        }
        cout<<endl;
    }

    unordered_map<int, bool> visited(false);
   
    for(int i=0; i<n; i++){
        if(!visited[i]){
             bool cycle = isCycleDFS(i, -1, adj, visited);
             if(cycle==true){
                cout<<"Cycle Detected!";
                return true;
             }
        }
    }

    cout<<"No Cycle Detected.";

    return 0;
}