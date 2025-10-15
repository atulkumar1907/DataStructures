#include<iostream>
#include ".\node.hpp"
using namespace std;

node*  reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;
    
    while(curr!=NULL){
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;

    }

    return prev;
}

node* reverseRecursive(node* &head){

    if((head==NULL) || (head->next==NULL)){
        return head;
    }

    node* newhead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;

}

node* reverseKnode(node* &head, int k){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;
    int count = 0;

    while(curr!=NULL && count<k){
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next = reverseKnode(nextptr, k);
    }

    return prev;
}

int main()
{

    node *head = NULL;
    for (int i = 1; i <= 6; i++)
    {
        insertAtTail(head, i);
    }

    // insertAtHead(head, 0);
    // insertAtTail(head, 5);

    print(head);

    // deletion(head, 2);
    // deleteAtHead(head);
    // deleteAtTail(head);

    // node* newHead = reverse(head);
    // node* newHead = reverseRecursive(head);
    // node* newHead = reverseKnode(head, 2);
    // print(newHead);

    cout<<length(head);

    return 0;
}