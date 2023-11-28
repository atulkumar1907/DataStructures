#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s;
    public:
    void enqueue(int x){
        s.push(x);
    }
    int pop(){
        if(s.empty()){
            cout<<"Queue is empty\n";
            exit(0);
        }

        int top = s.top();
        s.pop();
        if(s.empty()){
            return top;
        }

        int item = pop();
        s.push(top);
        return item;
    }

    bool empty(){
        if(s.empty()){
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

    cout<<q.pop();


    return 0;
}
