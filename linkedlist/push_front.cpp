#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node * next;

    Node(int val){
        this->val=val;
        next=NULL;
    }
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void pushBack(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
        }
        else {
            Node* cur = head;
            while(cur!=NULL){
                if(cur->next==NULL){
                    cur->next=newNode;
                    break;
                }
                cur=cur->next;
            }
        }
    }
    void pushFront(int val){
        Node* newNode= new Node(val);
        newNode->next=head;
        head=newNode;
    }
    void print(){
        Node* cur = head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->next;
        }
    }
};
int main(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.print();
    cout << endl;
    list.pushFront(10);
    list.print();
}