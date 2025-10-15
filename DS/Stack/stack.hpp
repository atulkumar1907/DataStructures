#include<iostream>
using namespace std;

#define n 100

class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int val){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(top==-1){
            cout<<"No Element"<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top==-1){
            cout<<"No Element"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }
};

