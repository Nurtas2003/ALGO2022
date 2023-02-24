#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int Value;
    Node* next;
};

void List(Node*n){
    while(n!=NULL){
        cout << n->Value << " ";
        n=n->next;
    }
}

void InsertFront(Node**head, int newvalue){
    Node*newnode=new Node();
    newnode->Value=newvalue;
    newnode->next=*head;
    *head=newnode;
}

void InsertEnd(Node** head, int newvalue){
    Node*newnode=new Node();
    newnode->Value=newvalue;
    newnode->next=NULL;

    if(*head==NULL){
        *head=newnode;
    }

    Node*last=*head;
    while(last->next!=NULL){
        last=last->next;
    }

    last->next=newnode;
}

void InsertAfter(Node*previous, int newvalue){
    if(previous==NULL){
        cout << "Previous can not be NULL" << " ";
    }
    Node*newnode=new Node();
    newnode->Value=newvalue;

    newnode->next=previous->next;
    previous->next=newnode;
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value=1;
    head->next=second;
    second->Value=2;
    second->next=third;
    third->Value=3;
    third->next=NULL;

    InsertAfter(head, -1);
    InsertAfter(second, -2);
    InsertAfter(third, -3);
    InsertFront(&head, -1);
    InsertEnd(&head, 4);
    List(head);
}