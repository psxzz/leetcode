#include <bits/stdc++.h>

/*
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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        ListNode* end = head;
        while (end != nullptr && end->next != nullptr) {
            end = end->next->next;
            mid = mid->next;
        }
        return mid;
    }
};

int main() {
    Solution s;

    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    ListNode* res = s.middleNode(l1);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    delete l1;
    return 0;
}