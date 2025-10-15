#include<iostream>
#include ".\node.hpp"
using namespace std;

void evenAfterOdd(node* head){

    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while(odd->next!=NULL && even->next!=NULL){

        odd->next = even->next;
        odd = odd->next;

        even->next=odd->next;
        even = even->next;
    }

    odd->next= evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}