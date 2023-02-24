#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class Linked{
    Node* head;
    Node* tail;

public:
    Linked(){
        head=NULL;
        tail=NULL;
    }

    void push_back(int val){
        Node* item = new Node(val);
        if(head==NULL){
            head=item;
        } else {
            Node* cur = head;
            while(cur!=NULL){
                if(cur->next==NULL){
                    cur->next=item;
                    break;
                }
                cur=cur->next;
            }
        }
    }
    // string front(){
    //     if(head!=NULL){
    //         return head->val;
    //     }
    // }
    // void pop_front(){
    //     if(head!=NULL){
    //         head=head->next;
    //     }
    // }

    void print(){
        Node* cur = head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->next;
        }
    }
};
int main(){
    Linked list;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(i%2==0){
            list.push_back(x);
        }
    }
    list.print();
}