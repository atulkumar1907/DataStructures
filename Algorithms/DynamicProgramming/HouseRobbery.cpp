#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num){
    int n = num.size();
    int prev2 = 0;
    int prev1 = num[0];

    for(int i=1; i<n; i++){
        int curr = max(num[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    } 

    return prev1;
}

int houseRobber(vector<int> &num){
    int n = num.size();

    if(n==1){
        return num[0];
    }

    vector<int> first(n), second(n);
    for(int i=0; i<n; i++){
        if(i!=n-1){
            first.push_back(num[i]);
        }

        if(i!=0){
            second.push_back(num[i]);
        }
    }

    return max(solve(first), solve(second));
}

int main(){

    return 0;
}