// LEETCODE 206 - REVERSE LINKED LIST

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseList(ListNode* head) {

    // Previous node initially NULL
    ListNode* prev = nullptr;

    // Current node starts from head
    ListNode* curr = head;

    while(curr != nullptr) {

        // Store next node
        ListNode* forward = curr->next;

        // Reverse link
        curr->next = prev;

        // Move prev and curr ahead
        prev = curr;
        curr = forward;
    }

    // prev becomes new head
    return prev;
}

void print(ListNode* head) {

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head = reverseList(head);

    print(head);

    return 0;
}