// LEETCODE 110 - BALANCED BINARY TREE

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

// Returns {isBalanced,height}
pair<bool,int> isBalancedFast(Node* root) {

    if(root == nullptr) {
        return {true,0};
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);

    bool leftBalanced = left.first;
    bool rightBalanced = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    bool currentNodeBalanced =
        leftBalanced &&
        rightBalanced &&
        diff;

    int height =
        max(left.second,right.second) + 1;

    return {currentNodeBalanced,height};
}

bool isBalanced(Node* root) {
    return isBalancedFast(root).first;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    if(isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}