#include<iostream>
#include<stack>
using namespace std;

class queue{
    public:
    stack<int> s1;
    stack<int> s2;

    void enqueue(int val){
        s1.push(val);
    }

    void dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
        return;
    }

    int front(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return  -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        
        return top;
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return true;
        }
        return false;
    }

};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;

    return 0;
}