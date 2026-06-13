// LEETCODE 100 - SAME TREE / IDENTICAL TREES

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

bool isIdentical(Node* root1, Node* root2) {

    // Both nodes are NULL
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }

    // One is NULL and other isn't
    if(root1 == nullptr || root2 == nullptr) {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);

    bool right = isIdentical(root1->right, root2->right);

    bool value = (root1->data == root2->data);

    return left && right && value;
}

int main() {

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    cout << isIdentical(root1, root2);

    return 0;
}