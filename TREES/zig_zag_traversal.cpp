// GFG - ZIG ZAG TREE TRAVERSAL

#include <iostream>
#include <vector>
#include <queue>
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

vector<int> zigZagTraversal(Node* root) {

    vector<int> result;

    if(root == nullptr)
        return result;

    queue<Node*> q;

    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {

        int size = q.size();

        vector<int> ans(size);

        for(int i=0; i<size; i++) {

            Node* front = q.front();
            q.pop();

            int index;

            if(leftToRight)
                index = i;
            else
                index = size - i - 1;

            ans[index] = front->data;

            if(front->left)
                q.push(front->left);

            if(front->right)
                q.push(front->right);
        }

        for(auto x : ans)
            result.push_back(x);

        leftToRight = !leftToRight;
    }

    return result;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = zigZagTraversal(root);

    for(int x : ans)
        cout << x << " ";

    return 0;
}