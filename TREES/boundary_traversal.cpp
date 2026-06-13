// GFG - BOUNDARY TRAVERSAL OF BINARY TREE

#include <iostream>
#include <vector>
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

bool isLeaf(Node* root) {

    return root->left == nullptr &&
           root->right == nullptr;
}

void leftBoundary(Node* root, vector<int>& ans) {

    Node* curr = root->left;

    while(curr) {

        if(!isLeaf(curr))
            ans.push_back(curr->data);

        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void leafBoundary(Node* root, vector<int>& ans) {

    if(root == nullptr)
        return;

    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }

    leafBoundary(root->left, ans);
    leafBoundary(root->right, ans);
}

void rightBoundary(Node* root, vector<int>& ans) {

    vector<int> temp;

    Node* curr = root->right;

    while(curr) {

        if(!isLeaf(curr))
            temp.push_back(curr->data);

        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i=temp.size()-1; i>=0; i--)
        ans.push_back(temp[i]);
}

vector<int> boundaryTraversal(Node* root) {

    vector<int> ans;

    if(root == nullptr)
        return ans;

    ans.push_back(root->data);

    leftBoundary(root, ans);

    leafBoundary(root->left, ans);
    leafBoundary(root->right, ans);

    rightBoundary(root, ans);

    return ans;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> ans = boundaryTraversal(root);

    for(int x : ans)
        cout << x << " ";

    return 0;
}