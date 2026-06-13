// LEETCODE 104 - HEIGHT OF BINARY TREE

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function returns height of tree
int height(Node* root) {

    // Empty tree
    if(root == nullptr) {
        return 0;
    }

    // Height of left subtree
    int leftHeight = height(root->left);

    // Height of right subtree
    int rightHeight = height(root->right);

    // Current height
    return max(leftHeight, rightHeight) + 1;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Height = " << height(root);

    return 0;
}
