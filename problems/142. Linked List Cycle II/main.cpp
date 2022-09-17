#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    std::unordered_set<ListNode *> s;
    ListNode *detectCycle(ListNode *head) {
        ListNode *tmp = head;
        while (tmp != nullptr) {
            if (s.count(tmp) != 0) return tmp;
            s.insert(tmp);
            tmp = tmp->next;
        }

        return nullptr;
    }
};

int main() {
    Solution s;

    ListNode *l1 = new ListNode(1);
    l1->next = l1;
    // l1->next->next = l1;

    ListNode *res = s.detectCycle(l1);

    std::cout << res << std::endl;

    return 0;
}