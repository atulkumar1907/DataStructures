#include<bits/stdc++.h>
using namespace std;

int mergeOptimal(int arr[], int n){

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    } 

    int cost = 0;

    while(pq.size()>1){
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int mergeLength = first + second;
        cost += mergeLength;

        pq.push(mergeLength);
    }

    return cost;
}

int main(){
    int arr[] = {5, 2, 4, 7};
    int n = 4;

    cout<<mergeOptimal(arr, n);
    return 0;
}