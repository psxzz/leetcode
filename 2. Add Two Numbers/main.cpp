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
    ListNode* recursive(ListNode* l1, ListNode* l2, int add) {
        if (!l1 && !l2 && !add)
            return nullptr;
        else if (!l1 && !l2 && add)
            return new ListNode(add, 0);

        int left = (!l1) ? 0 : l1->val;
        int right = (!l2) ? 0 : l2->val;
        ListNode* nextLeft = (!l1) ? nullptr : l1->next;
        ListNode* nextRight = (!l2) ? nullptr : l2->next;

        int sum = left + right + add;
        int remains = sum / 10;
        int value = sum % 10;

        ListNode* res = new ListNode(value, recursive(nextLeft, nextRight, remains));
        return res;
    }

   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = recursive(l1, l2, 0);
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

    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode* res = s.addTwoNumbers(l1, l2);

    s.printList(res);

    return 0;
}