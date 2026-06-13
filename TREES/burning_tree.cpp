// GFG - BURNING TREE

#include <iostream>
#include <queue>
#include <unordered_map>

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

// Create parent mapping + find target node
Node* createParentMapping(
        Node* root,
        int target,
        unordered_map<Node*,Node*>& parent)
{
    Node* res = nullptr;

    queue<Node*> q;
    q.push(root);

    parent[root] = nullptr;

    while(!q.empty()) {

        Node* front = q.front();
        q.pop();

        if(front->data == target)
            res = front;

        if(front->left) {
            parent[front->left] = front;
            q.push(front->left);
        }

        if(front->right) {
            parent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int burnTree(
        Node* targetNode,
        unordered_map<Node*,Node*>& parent)
{
    unordered_map<Node*,bool> visited;

    queue<Node*> q;

    q.push(targetNode);
    visited[targetNode] = true;

    int time = 0;

    while(!q.empty()) {

        int size = q.size();

        bool burnedNewNode = false;

        for(int i=0;i<size;i++) {

            Node* front = q.front();
            q.pop();

            // left child
            if(front->left &&
               !visited[front->left])
            {
                burnedNewNode = true;

                visited[front->left] = true;
                q.push(front->left);
            }

            // right child
            if(front->right &&
               !visited[front->right])
            {
                burnedNewNode = true;

                visited[front->right] = true;
                q.push(front->right);
            }

            // parent
            if(parent[front] &&
               !visited[parent[front]])
            {
                burnedNewNode = true;

                visited[parent[front]] = true;
                q.push(parent[front]);
            }
        }

        if(burnedNewNode)
            time++;
    }

    return time;
}

int minTime(Node* root, int target) {

    unordered_map<Node*,Node*> parent;

    Node* targetNode =
        createParentMapping(
            root,
            target,
            parent);

    return burnTree(targetNode,parent);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << minTime(root,5);

    return 0;
}