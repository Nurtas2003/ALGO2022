#include <bits/stdc++.h>
using namespace std;
int sum=0;
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

    void level(Node* cur, int x){
        if(cur==NULL){
            return;
        }
        level(cur->left, x+1);
        sum+=cur->val - x;
        level(cur->right, x+1);
    }

    void print(Node* cur){
        if(cur!=NULL){
            print(cur->left);
            cout << cur->val << " ";
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

    void level(){
        level(root, 0);
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
    // tree.print();
    tree.level();
    cout << sum << endl;
}