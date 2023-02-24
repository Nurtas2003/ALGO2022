#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    string s;
    Node* next;

    Node(int val, string s){
        this->val=val;
        this->s=s;
        next=NULL;
    }
};

class LinkedList{
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void push(int val, string s){
        Node* newNode = new Node(val, s);
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
    void print(){
        Node* cur=head;
        while(cur!=NULL){
            cout << cur->val << " " << cur->s << endl;
            cur=cur->next;
        }
    }
};

int main(){
    LinkedList list;
    list.push(1, "Nurtas");
    list.push(2, "Madi");
    list.push(3, "Nursat");
    list.push(4, "Aibergen");
    list.push(5, "Adema");
    list.print();
}