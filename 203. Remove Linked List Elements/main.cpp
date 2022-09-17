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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        ListNode* tmp = head;
        while (tmp != nullptr) {
            if (tmp->val != val) {
                dummy->next = tmp;
                dummy = dummy->next;
            }
            tmp = tmp->next;
        }

        dummy->next = tmp;

        return res->next;
    }

    void printList(ListNode* h) {
        ListNode* tmp = h;

        while (tmp != nullptr) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    ListNode* l1 = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                6, new ListNode(
                       3, new ListNode(4, new ListNode(5, new ListNode(6)))))));

    ListNode* l2 =
        new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));

    ListNode* res = s.removeElements(l2, 7);

    s.printList(res);

    return 0;
}