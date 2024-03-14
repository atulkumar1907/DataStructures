#include<iostream>
#include<queue>
using namespace std;

int kthSmallest(int arr[], int r, int k){
    priority_queue<int> pq;

    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k; i<r; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}


int main(){

    int arr[6] = {6, 9, 2, 5, 1, 7};

    cout<<kthSmallest(arr, 6, 3);


    return 0;
}