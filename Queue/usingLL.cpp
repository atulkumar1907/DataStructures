#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    public:
    node* front;
    node* back;

    queue(){
        front=NULL;
        back=NULL;
    }
    void enqueue(int val);
    void dequeue();
    int Front();
    bool empty();
};

void queue:: enqueue(int val){
    node* n = new node(val);
    
    if(front==NULL){
        front=n;
        back=n;
        return;
    }
    back->next=n;
    back=n;
}

void queue:: dequeue(){
    if(front==NULL){
        cout<<"No Element\n";
        return;
    }
    node* todel=front;
    front=front->next;
    delete todel;
}

int queue::Front(){
    if(front==NULL){
        cout<<"No Element\n";
        return -1;
    }
    return front->data;
}

bool queue:: empty(){
    if(front==NULL){
        return true;
    }
    return false;
}

int main(){

    queue q;
    q.enqueue(5);
    cout<<q.Front();
    cout<<q.empty();
    cout<<"kjfdkf";

    return 0;
}