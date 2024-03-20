#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

bool checkCycle(int n, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj){
    visited[n] = 1;
    dfsvisited[n] = 1;

    for(auto i: adj[n]){
        if(!visited[i]){
            bool cycle = checkCycle(i, visited, dfsvisited, adj);
            if(cycle) return true;
        }
        else if(dfsvisited[n]){
            return true;
        }
    }
    dfsvisited[n] = 0;
    return false;
}


int main(){

    int u, v;
    cin>>u>>v;

    unordered_map<int,list<int>> adj;

    for(int i=0; i<v; i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
    }

    unordered_map<int, bool> visited(false);
    unordered_map<int, bool> dfsvisited(false);

    for(int i=0; i<u; i++){
        if(!visited[i]){
            bool cycleFound = checkCycle(i, visited, dfsvisited, adj);
            if(cycleFound) {
                cout<<"yes";
                return true;
            }
        }
    }
    cout<<"NO";

    return 0;
}