#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* to_delete = dummy;
        ListNode* end = head;

        for (size_t i = 0; i < n && end != nullptr; ++i) {
            end = end->next;
        }

        while (end != nullptr) {
            end = end->next;
            to_delete = to_delete->next;
        }

        to_delete->next = to_delete->next->next;

        return dummy->next;
    }

    void printList(ListNode* l) {
        ListNode* tmp = l;
        while (tmp != nullptr) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    ListNode* l1 = new ListNode(1, new ListNode(2));
    s.printList(l1);

    ListNode* res1 = s.removeNthFromEnd(l1, 2);
    s.printList(res1);

    delete l1;
    return 0;
}