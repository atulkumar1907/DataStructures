#include<iostream>
#include ".\node.hpp"
using namespace std;

void makeCycle(node* head, int pos){
    node* temp = head;
    node* startnode;
    int count = 1;

    while(temp->next!=NULL){
        if(count==pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool detectCycle(node* &head){

    node* fast = head;
    node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast==slow){
            return true;
        }
    }
    
    return false;
}

void removeCycle(node* &head){
    node* fast = head;
    node* slow = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast!=slow);

    fast = head;
    while(fast->next!=slow->next){
        fast= fast->next;
        slow= slow->next;
    }

    slow->next = NULL;
}

int main(){

    node *head = NULL;
    for (int i = 1; i <= 9; i++)
    {
        insertAtTail(head, i);
    }

    print(head);
    makeCycle(head, 4);
    // removeCycle(head);

    cout<<detectCycle(head);
    return 0;
}