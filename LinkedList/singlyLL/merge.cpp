#include<iostream>
#include ".\node.hpp"
using namespace std;

node* merge(node* &head1, node* &head2){
    node* dummy=new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummy;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next= ptr2;
            ptr2=ptr2->next;
        }

        ptr3=ptr3->next;
    }

    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
     return dummy;
}

node* mergeRecursive(node* &head1, node* &head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);

        return result;
    }
}