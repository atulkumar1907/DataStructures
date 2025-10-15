#include<iostream>
#include<vector>
// #include<math>
#include<climits>
using namespace std;

// swap two elements in an array
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// selection sort
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr, i, j);
            }
        }
    }
}

// bubble sort
void bubbleSort(int arr[], int n){
    int counter =1;

    while(counter<n-1){
        for(int i=0; i<n-counter; i++){
            if(arr[i]>arr[i+1]){
                swap(arr, i, i+1);
            }
        }
        counter++;
    }
   
}

// insertion sort
void insertionSort(int arr[], int n){

    for(int i=0; i<n; i++){
        int curr = arr[i];
        int j = i-1;
        while(j>0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}


// merge sort

void merge(int arr[], int l, int mid, int r){


    int n1 = mid-l+1;
    int n2 = r-mid;

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

}

void mergeSort(int arr[], int l, int r){
    if(l<r){

        int mid = (l+r)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

// quick sort

int partition(int arr[], int l, int r){
    int pivot = arr[r];

    int i=l-1;
    for(int j=l; j<=r; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, r);

    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l<r){

        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

// count sort

void countSort(int arr[], int n){
    int k = arr[0];
    for(int i=1; i<n; i++){
        k = max(arr[i], k);
    }

    int count[10];
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=0; i<=k; i++){
        count[i] +=count[i-1];
    }

    int op[n];
    for(int i=n-1; i>=0; i--){
        op[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = op[i];
    }

}

// DNF Sort
void dnf(int arr[], int n){
    int low = 0, high = n-1;
    int mid =0;
    
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr, low, mid);
            low++; mid++;
        }
        else if(arr[mid] ==1){
            mid++;
        }
        else{
            swap(arr, mid, high);
            high--;
        }
    }
}

void waveSort(int arr[], int n){

    for(int i=1; i<n-1; i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr, i, i-1);
        }
        if(arr[i]>arr[i+1]){
            swap(arr, i, i+1);
        }
    }
}
