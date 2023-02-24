#include <bits/stdc++.h>

using namespace std;

class Bst {
private:
    vector<int> res;
    int curSum = 0;

    struct Node{

        Node(int x) {
            val = x;
        }

        int val;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    Node *root = nullptr;

    void add(Node *node, int x) {
        if(node->val > x) {
            if (node->left)
                add(node->left, x);
            else
                node->left = new Node(x);
        } else {
            if(node->right)
                add(node->right, x);
            else
                node->right = new Node(x);
        }
    }

    void getSums(Node *node) {
        if(!node)
            return;
        getSums(node->right);
        curSum += node->val;
        res.push_back(curSum);
        getSums(node->left);
    }

public:

    void add(int x) {
        if(!root)
            root = new Node(x);
        else
            add(root, x);
    }

    vector<int> getSums() {
        getSums(root);
        return res;
    }

};

int main() {

    Bst bst;

    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        bst.add(x);
    }

    vector<int> res = bst.getSums();
    for(int i : res)
        cout << i << " ";


    return 0;
}