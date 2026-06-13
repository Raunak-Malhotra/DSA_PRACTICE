// LEETCODE 19 - REMOVE NTH NODE FROM END

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

ListNode* removeNthFromEnd(
        ListNode* head,
        int n)
{
    ListNode dummy(0);

    dummy.next = head;

    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    // Move fast n+1 steps
    for(int i=0;i<=n;i++) {
        fast = fast->next;
    }

    while(fast) {

        slow = slow->next;
        fast = fast->next;
    }

    ListNode* nodeToDelete = slow->next;

    slow->next = nodeToDelete->next;

    delete nodeToDelete;

    return dummy.next;
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
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = removeNthFromEnd(head,2);

    print(head);

    return 0;
}