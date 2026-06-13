// LEETCODE 543 - DIAMETER OF BINARY TREE

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
        left = right = nullptr;
    }
};

// Returns {diameter,height}
pair<int,int> diameterFast(Node* root) {

    if(root == nullptr) {
        return {0,0};
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;

    int op3 = left.second + right.second;

    int diameter = max(op1, max(op2, op3));

    int height = max(left.second, right.second) + 1;

    return {diameter,height};
}

int diameter(Node* root) {
    return diameterFast(root).first;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Diameter = " << diameter(root);

    return 0;
}