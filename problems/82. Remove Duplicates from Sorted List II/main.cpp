#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr) {
            if (curr->next && curr->next->next &&
                curr->next->val == curr->next->next->val) {
                ListNode* tmp = curr->next->next;
                while (tmp && tmp->next && tmp->val == tmp->next->val)
                    tmp = tmp->next;

                curr->next = tmp->next;
            } else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }

    void printList(ListNode* head) {
        ListNode* tmp = head;

        while (tmp != nullptr) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    Solution  s;
    ListNode* l1 = new ListNode(
        1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3)))));

    auto res = s.deleteDuplicates(l1);

    s.printList(res);

    return 0;
}