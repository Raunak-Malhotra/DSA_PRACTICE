// LEETCODE 21 - MERGE TWO SORTED LINKED LISTS

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // Dummy node simplifies handling head
    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while(list1 && list2) {

        if(list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    // Attach remaining nodes
    if(list1)
        tail->next = list1;

    if(list2)
        tail->next = list2;

    return dummy.next;
}

void print(ListNode* head) {

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* ans = mergeTwoLists(list1,list2);

    print(ans);

    return 0;
}