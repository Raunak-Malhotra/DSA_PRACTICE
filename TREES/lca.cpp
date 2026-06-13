// LEETCODE 236 - LOWEST COMMON ANCESTOR OF A BINARY TREE

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* LCA(Node* root, Node* p, Node* q) {

    // Base Case
    if(root == nullptr)
        return nullptr;

    // One of the nodes found
    if(root == p || root == q)
        return root;

    Node* leftAns = LCA(root->left, p, q);
    Node* rightAns = LCA(root->right, p, q);

    // Both sides returned a node
    if(leftAns && rightAns)
        return root;

    // Only left side found
    if(leftAns)
        return leftAns;

    // Only right side found
    return rightAns;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* ans = LCA(root, root->left, root->right);

    cout << "LCA = " << ans->data;

    return 0;
}