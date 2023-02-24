#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        next = NULL;
    }
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void push(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head = newNode;
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
    void print(){
        Node* cur= head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur= cur->next;
        }
    }
};

int main(){
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.print();
}