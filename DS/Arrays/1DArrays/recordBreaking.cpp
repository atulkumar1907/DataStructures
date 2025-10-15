#include<iostream>
using namespace std;

int recordBreakingDay(int arr[], int n){
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;

    for(int i=0; i<n; i++){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            ans++;
        }
        mx = max(mx, arr[i]);
    }
    return ans;
}


int main(){
    int n = 8;
    int arr[n+1] = {1, 2, 0, 7, 2, 0, 2, 2, -1};

    int ans  = recordBreakingDay(arr, n);
    cout<<ans;
}
