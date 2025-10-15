#include<iostream>
using namespace std;

// bool search(int arr[][], int n, int m, int k){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(arr[i][j]==k){
//                 cout<<"Element found"<<endl;
//                 return true;
//             }
//         }
//     }
//     return false;

// }

int main(){


    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int k; cin>>k;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(arr[i][j]==k){
    //             cout<<"Element found"<<endl;
    //             return true;
    //         }
    //     }
    // }

    int r=0, c=m-1;
    while(r<n && c>=0){
        if(arr[r][c]==k){
            cout<<"Element found";
            return 0;
        }
        else if(arr[r][c]>k){
            c--;
        }
        else{
            r++;
        }
    }

}