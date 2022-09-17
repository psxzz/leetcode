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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* res = new ListNode(head->val);
        ListNode* tmp_res = res;
        ListNode* tmp = head->next;

        while (tmp != nullptr) {
            if (tmp->val != tmp_res->val) {
                tmp_res->next = tmp;
                tmp_res = tmp_res->next;
            }
            tmp = tmp->next;
        }
        tmp_res->next = tmp;

        return res;
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
    ListNode* l1 = new ListNode(1, new ListNode(1, new ListNode(2)));

    ListNode* res1 = s.deleteDuplicates(l1);

    s.printList(res1);

    return 0;
}