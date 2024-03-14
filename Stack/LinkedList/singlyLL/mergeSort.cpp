#include<iostream>
#include "node.hpp"

using namespace std;

node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left ==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while(left!=NULL || right!=NULL){
        if(left->data<right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!=NULL){
         temp->next = right;
            temp = right;
            right = right->next;
    }
    return ans->next;
}

node* mergeSort(node* head){
    if(head==NULL || head->next==NULL) return head;

    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);

    return result;
}

int main(){
    node* head = new node(1);
     head->next = new node(5);
     head->next->next = new node(2);
     head->next->next->next = new node(9);
    head->next->next->next->next = new node(3);

    // print(head);

    node* ans = mergeSort(head);

    print(ans);


    return 0;
}