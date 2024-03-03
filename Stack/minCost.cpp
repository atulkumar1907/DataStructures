#include<iostream>
#include<stack>
using namespace std;

int minCost(string s){
    if(s.length()%2==1){
        return -1;
    }

    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    int a=0; int b=0;
    while(!st.empty()){
            if(st.top()=='('){
                b++;
            }
            else{
                a++;
            }
            st.pop();
        }

        int ans = (a+1)/2 + (b+1)/2;
}