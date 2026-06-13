// LEETCODE 234 - PALINDROME LINKED LIST

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

// Reverse linked list
ListNode* reverse(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr) {

        ListNode* forward = curr->next;

        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {

    if(head == nullptr || head->next == nullptr)
        return true;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    slow->next = reverse(slow->next);

    ListNode* first = head;
    ListNode* second = slow->next;

    while(second) {

        if(first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << isPalindrome(head);

    return 0;
}