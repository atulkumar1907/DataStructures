#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int> &nums, int k){

    int n = nums.size();

    vector<int> temp(n);

    for(int i=0; i<n; i++){
        temp[(i+k)%n] = nums[i];
    }

    nums = temp;
}

int main(){

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    for(auto i: nums){
        cout<<i<<" ";
    }cout<<endl;
    
    rotateArray(nums, k);

    for(auto i: nums){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}