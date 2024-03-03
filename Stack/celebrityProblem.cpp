#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>& M, int n){
    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(i);
    }

    while(st.size()>1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(M[a][b]==1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int candidate = st.top();
    
    int zeroCount = 0;
    for(int i=0; i<n; i++){
        if(M[candidate][i]==0){
            zeroCount++;
        }
    }

    if(zeroCount!=n){
        return -1;
    }

    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(M[i][candidate]==1){
            oneCount++;
        }
    }

    if(oneCount!=n-1){
      return -1;
    }

    return candidate;
}
    

int main(){
    vector<vector<int>> a;
    a.resize(3, vector<int>(3));

    cout<<"Enter the matrix: "<<endl;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }

    cout<<celebrity(a, 3);


}