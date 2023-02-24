#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        right=left=NULL;
    }
};
int a[100005];
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

    int toLeft(Node* cur){
        if(cur==NULL) return 0;
        return toLeft(cur->left)+1;
    }

    int toRight(Node* cur){
        if(cur==NULL) return 0;
        return toRight(cur->right)+1;
    }

    void check(Node* cur){
        if(cur==NULL) return;
        int l = toLeft(cur->left);
        int r = toRight(cur->right);
        int cnt=min(l, r);
        for(int i=1; i<=cnt; i++){
            a[i]++;
        }
        check(cur->left);
        check(cur->right);
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

    void check(){
        check(root);
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
    tree.check();

    for(int i=1; i<n; i++){
        cout << a[i] << " ";
    }
}