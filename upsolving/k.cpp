#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        next=prev=NULL;
    }
};

class LL{
    Node* head;
    Node* tail;
public:
    LL(){
        head=tail=NULL;
    }

    void push_back(int val){
        Node* item = new Node(val);
        if(head==NULL){
            head=tail=item;
        } else {
            tail->next=item;
            item->prev=tail;
            tail=item;
        }
    }

    void push_front(int val){
        Node* item= new Node(val);
        if(head==NULL){
            head=tail=item;
        } else {
            item->next=head;
            head->prev = item;
            head=item;
        }
    }

    void print_back(){
        Node* cur = head;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->next;
        }
    }

    void print_front(){
        Node* cur = tail;
        while(cur!=NULL){
            cout << cur->val << " ";
            cur=cur->prev;
        }
    }
};

int main(){
    int n;
    cin >> n;
    LL list;
    bool ok=false;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(x==1 && ok==false){
            int m; cin >> m;
            list.push_back(m);
        }if(x==1 && ok==true){
            int m; cin >> m;
            list.push_front(m);
        } else if(x==2){
            ok=!ok;
        }
    }
    if(ok==true){
        list.print_front();
    } else {
        list.print_back();
    }
}