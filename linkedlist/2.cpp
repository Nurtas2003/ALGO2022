#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int Value;
    Node* next;
};

void List(Node* n){
    while(n!=NULL){
        cout << n->Value << " ";
        n=n->next;
    }
}

void INSERTFRONT(Node**head, int newValue){
    Node* newNode = new Node();
    newNode->Value = newValue;
    newNode->next=*head;
    *head=newNode;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third=NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->Value =  1;
    head->next = second;
    second->Value = 2;
    second->next = third;
    third->Value = 3;
    third->next=NULL;

    INSERTFRONT(&head, -2);
    INSERTFRONT(&head, -1);
    List(head);

    return 0;
}