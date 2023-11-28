#include<iostream>
using namespace std;

// Brute Force
int inv(int arr[], int n){
    int inv=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(arr[i]>arr[j] && i<j){
                inv++;
            }
        }
    }
    return inv;
}

// using merge sort

long long merge(int arr[], int l, int mid, int r){
    long long inv=0;

    int n1 = mid-l+1;
    int n2 = r-mid; // r- (mid+1) -1

    int a[n1], b[n2];

    for(int i=0; i<n1; i++){
        a[i] = arr[l+i];
    }

    for(int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }

    int i=0, j=0;
    int k = l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++; i++;
        }
        else{
            arr[k] = b[j];
            inv+= n1-i;
            k++; j++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        k++; i++;
    }

    while(j<n2){
        arr[k] = b[j];
        k++; j++;
    }

    return inv;
}

long long mergeSort(int arr[], int l, int r){

    long long inv=0;

    if(l<r){

        int mid = (l+r)/2;

        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid+1, r);

        inv += merge(arr, l, mid, r);
    }

    return inv;
}

int main(){

    int arr[] {3, 5, 6, 9, 1, 2, 7, 8};

    cout<<inv(arr, 8)<<endl;

    cout<<mergeSort(arr, 0, 7);

    return 0;
}