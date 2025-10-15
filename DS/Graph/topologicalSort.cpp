#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>

using namespace std;

vector<int> kahnsSort(int n, unordered_map<int, list<int>> &adj, vector<int> &indegree, vector<int> &ans){
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }


    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour: adj[front]){
            indegree[front]--;

            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }

    }

    return ans;
}


void topSort(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s){
    visited[i] = 1;

    for(auto j: adj[i]){
        if(!visited[j]){
            topSort(j, visited, adj, s);
        }
    }

    s.push(i);
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
    stack<int> s;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            topSort(i, visited, adj, s);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    vector<int> indegree(n);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    vector<int> ans;
    kahnsSort(n, adj, indegree, ans);



    return 0;
}