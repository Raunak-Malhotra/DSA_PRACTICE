// GFG - TOP VIEW OF BINARY TREE

#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

vector<int> topView(Node* root) {

    vector<int> ans;

    if(root == nullptr)
        return ans;

    map<int,int> topNode;

    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()) {

        auto temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // First node encountered
        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left)
            q.push({frontNode->left, hd-1});

        if(frontNode->right)
            q.push({frontNode->right, hd+1});
    }

    for(auto i : topNode)
        ans.push_back(i.second);

    return ans;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> ans = topView(root);

    for(int x : ans)
        cout << x << " ";

    return 0;
}