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
    }

    void reverse(){
        vector<int> rave;
        Node* cur=head;
        while(cur!=NULL){
            rave.push_back(cur->val);
            cur=cur->next;
        }
        // for(int i=0; i<rave.size(); i++){
        //     cout << rave[i] << " ";
        // }
        cur=head;
        int i=rave.size()-1;
        while(cur!=NULL){
            cur->val=rave[i];
            cur=cur->next;
            i--;
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
    int n;
    cin >> n;
    LinkedList list;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(x==1){
            int m; cin >> m;
            list.push_back(m);
            // list.print();
            // cout << endl;
        } else if(x==2){
            list.reverse();
            // list.print();
            // cout << endl;
        }
    }
    list.print();
}