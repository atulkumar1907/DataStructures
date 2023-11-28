#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;

void helper(vector<int> a, vector<vector<int>> &ans, int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }

    for(int i=idx; i<a.size(); i++){
       if(i!=idx && a[i]==a[idx]){
        continue;
       }
       swap(a[i], a[idx]);
       helper(a, ans, idx+1);
    }
    return ;

}

vector<vector<int>>  permute2(vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

void permute(vector<int> &a, int idx){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }

    for(int i=idx; i<a.size(); i++){
        swap(a[i], a[idx]);
        permute(a, idx+1);
        swap(a[i], a[idx]);
    }
    return ;
}



int main(){
    
    int n; cin>>n;

    vector<int> a(n);
    for(auto &i : a){
        cin>>i;
    }
    // permute(a, 0);

    // sort(a.begin(), a.end());
    // do{
    //     ans.push_back(a);
    // }while(next_permutation(a.begin(), a.end()));

    vector<vector<int>> ans = permute2(a);

    for(auto v: ans){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }


    return 0;
}