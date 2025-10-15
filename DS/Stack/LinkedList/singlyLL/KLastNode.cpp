#include<iostream>
#include ".\node.hpp"
using namespace std;

node* appendKnode(node* &head, int k){

    node* newHead;
    node* newTail;
    node* temp=head;

    int count = 1;
    int l = length(head);
    k = k%l;

    while(temp->next!=NULL){

        if(count==l-k){
            newTail = temp;
        }
        if(count==l-k+1){
            newHead = temp;
        }
        temp=temp->next;
        count++;
    }
    newTail->next = NULL;
    temp->next = head;

    return newHead;
}

int main(){

    node *head = NULL;
    for (int i = 1; i <= 6; i++)
    {
        insertAtTail(head, i);
    }

    print(head);
    node* newHead = appendKnode(head, 3);
    print(newHead);

    return 0;
}