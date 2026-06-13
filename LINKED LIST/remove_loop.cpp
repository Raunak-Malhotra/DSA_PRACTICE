// GFG - REMOVE LOOP IN LINKED LIST

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* detectCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return slow;
    }

    return nullptr;
}

void removeLoop(Node* head) {

    Node* intersection = detectCycle(head);

    if(intersection == nullptr)
        return;

    Node* ptr1 = head;
    Node* ptr2 = intersection;

    while(ptr1 != ptr2) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    Node* startOfLoop = ptr1;

    Node* temp = startOfLoop;

    while(temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = nullptr;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->next->next = head->next;

    removeLoop(head);

    return 0;
}