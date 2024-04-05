#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define rep(i, a, b) for(int i=a; i<b; i++)

const int INF = 1e9;

int main(){

    vector<vector<int>> g = {
                                {0,5 , INF, 10},
                                {INF, 0, 3, INF},
                                {INF, INF, 0, 1},
                                {INF, INF, INF, 0}
                            };

    int n = g.size();
    vector<vector<int>> dist = g;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k]+ dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j]==INF){
                cout<<"INF ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}