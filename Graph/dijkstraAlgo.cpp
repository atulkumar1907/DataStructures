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

    vector<int> dist(n);
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;    
    }

    int src = 0;

    set<pair<int, int>> st;
    dist[src]= 0;
    st.insert(make_pair(0, src));

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDis = top.first;
        int node = top.second;

        st.erase(st.begin());

        for(auto neighbour: adj[node]){
            if(nodeDis + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record!=st.end()){
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDis + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

}