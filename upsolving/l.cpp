#include <bits/stdc++.h>
using namespace std;
int cnt=0;
struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        right=left=NULL;
    }
};

class BST{
private:
    Node* root;
    Node* push(Node* cur, int val){
        if(cur==NULL){
            return new Node(val);
        } 
        if(val<cur->val) cur->left = push(cur->left, val);
        if(val>cur->val) cur->right = push(cur->right, val);
        return cur;
    }

    void print(Node* cur){
        if(cur!=NULL){
            print(cur->left);
            if(cur->left==NULL && cur->right==NULL) cnt++;
            print(cur->right);
        }
    }

public:
    BST(){
        root=NULL;
    }

    void push(int val){
        root=push(root, val);
    }

    void print(){
        print(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.print();
    cout << cnt << endl;
}