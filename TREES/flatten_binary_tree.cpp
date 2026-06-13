// GFG - BINARY TREE TO DOUBLY LINKED LIST

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

void solve(
    Node* root,
    Node*& head,
    Node*& prev)
{
    if(root == nullptr)
        return;

    // Right subtree first
    solve(root->right, head, prev);

    // Current node connection
    if(prev == nullptr) {

        head = root;
    }
    else {

        root->right = prev;
        prev->left = root;
    }

    prev = root;

    // Left subtree
    solve(root->left, head, prev);
}

Node* binaryTreeToDLL(Node* root) {

    Node* head = nullptr;
    Node* prev = nullptr;

    solve(root, head, prev);

    return head;
}

int main() {

    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    Node* head = binaryTreeToDLL(root);

    while(head) {

        cout << head->data << " ";
        head = head->right;
    }

    return 0;
}