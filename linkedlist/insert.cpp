#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        next=NULL;
    }
};

class LinkedList{
    Node* head;
    int size;

public:
    LinkedList(){
        head=NULL;
        size=0;
    }

    void push_back(int val){
        Node* newNode=new Node(val);
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
        size++;
    }
    void push_front(int val){
        Node* newNode= new Node(val);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void add(int pos, int val){
        if(pos>=size){
            cout << "can't add";
            return;
        }
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node* cur = head;
            int i=1;
            while(cur!=NULL){
                if(i==pos){
                    newNode->next=cur->next;
                    cur->next=newNode;
                    break;
                }
                cur=cur->next;
                i++;
            }
        }
        size++;
    }
    void insert(int pos, int val){
        if(pos>=size){
            cout << "can't insert";
            return;
        }
        Node* cur = head;
        int i=1;
        while(cur!=NULL){
            if(i==pos){
                cur->val=val;
                break;
            }
            cur=cur->next;
            i++;
        }
    }
    void print(){
        Node* cur=head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->next;
        }
    }
};
int main(){
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.print();
    cout << endl;
    list.push_front(10);
    list.print();
    cout << endl;
    list.add(2, 15);
    list.print();
    cout << endl;
    list.insert(2, 100);
    list.print();
}