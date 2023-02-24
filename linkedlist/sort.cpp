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
        size++;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void add(int pos, int val){
        if(pos>=size){
            cout<<"can't add";
            return;
        }
        Node* newNode= new Node(val);
        if(head==NULL){
            head=newNode;
        } 
        else {
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
            cout<<"can't insert";
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

    void del1(int val){
        if(head==NULL){
            cout<<"Linked lists is empty";
            return;
        }
        if(head->val==val){
            head=head->next;
        }
        else {
            Node* cur= head;
            Node* prev= NULL;
            while(cur!=NULL){
                if(cur->val==val){
                    prev->next=cur->next;
                    delete cur;
                    return;
                }
                prev=cur;
                cur=cur->next;
            }
            cout << "No such element value " << val << endl;
        }
        size--;
    }

    void del2(int pos){
        if(head==NULL){
            cout << "Linked list is empty " << endl;
            return;
        }
        if(pos<=0){
            cout << "No such pos " << pos << endl;
        }
        if(pos==1){
            head=head->next;
        }
        else {
            int i=1;
            Node* cur= head;
            Node* prev= NULL;
            while(cur!=NULL){
                if(i==pos){
                    prev->next=cur->next;
                    delete cur;
                    return;
                }
                prev=cur;
                cur=cur->next;
                i++;
            }
            cout << "No such element pos " << pos << endl;
        }
    }

    void sort(){
        Node * first = head;
        Node * second = NULL;
        if(head==NULL){
            return;
        }
        while(first->next!=NULL){
            second=first->next;
            while(second!=NULL){
                if(first->val>second->val){
                    swap(first->val, second->val);
                }
                second=second->next;
            }
            first=first->next;
        }
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
    cout << endl;
    list.del1(3);
    list.print();
    list.del2(2);
    cout << endl;
    list.print();
    cout << endl;
    list.sort();
    list.print();
}