#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int ele){
    if(s.empty()){
        s.push(ele);
        return;
    }

    int topEle = s.top();
    s.pop();

    insertAtBottom(s, ele);

    s.push(topEle);
}

void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }

    int topEle = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, topEle);

    return;
}


int main(){

    stack<int> st;
    for(int i=1; i<5; i++){
        st.push(i);
    }

    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    

    return 0;
}