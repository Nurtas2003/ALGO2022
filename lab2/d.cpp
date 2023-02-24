#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;
    int cnt;

    Node(int val){
        this->val=val;
        cnt=1;
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
        Node* item=new Node(val);
        if(head==NULL){
            head=item;
        } else {
            Node* cur = head;
            while(cur!=NULL){
                if(cur->val==val){
                    cur->cnt++;
                } else if(cur->next==NULL){
                    cur->next=item;
                    break;
                }
                cur=cur->next;
            }
        }
    }

    int max_Cnt(){
        Node* cur = head;
        int maxi=1;
        while(cur!=NULL){
            if(cur->cnt>maxi){
                maxi=cur->cnt;
            }
            cur=cur->next;
        }
        return maxi;
    }

    void Step2(){
        vector<int>v;
        Node* cur = head;
        while(cur!=NULL){
            if(cur->cnt==max_Cnt()){
                v.push_back(cur->val);
            }
            cur=cur->next;
        }
        sort(v.rbegin(), v.rend());
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
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
        list.push_back(x);
    }
    list.Step2();
}