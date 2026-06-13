// LEETCODE 138 - COPY LIST WITH RANDOM POINTER

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {

    if(head == nullptr)
        return nullptr;

    // Mapping: original node -> cloned node
    unordered_map<Node*, Node*> mp;

    Node* temp = head;

    // Step 1: Create clone nodes
    while(temp) {

        mp[temp] = new Node(temp->val);

        temp = temp->next;
    }

    temp = head;

    // Step 2: Connect next and random pointers
    while(temp) {

        mp[temp]->next = mp[temp->next];

        mp[temp]->random = mp[temp->random];

        temp = temp->next;
    }

    return mp[head];
}

void print(Node* head) {

    while(head) {

        cout << "Node = " << head->val;

        if(head->random)
            cout << " Random = " << head->random->val;

        cout << endl;

        head = head->next;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;      // 1 -> 3
    head->next->random = head;            // 2 -> 1
    head->next->next->random = head->next;// 3 -> 2

    Node* clonedList = copyRandomList(head);

    print(clonedList);

    return 0;
}