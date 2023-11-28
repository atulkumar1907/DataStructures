#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void deletion(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}

void deleteAtHead(node *&head)
{

    node *todel = head;
    head = head->next;

    delete todel;
}
void deleteAtTail(node *&head)
{

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *todel = temp->next;
    temp->next = NULL;
    delete todel;
}

int length(node* head){
    int l=0;
    node* temp = head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

