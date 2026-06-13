// LEETCODE 141 - LINKED LIST CYCLE

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

bool hasCycle(ListNode* head) {

    if(head == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr &&
          fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        // Meeting point found
        if(slow == fast)
            return true;
    }

    return false;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // Creating cycle
    head->next->next->next = head;

    cout << hasCycle(head);

    return 0;
}