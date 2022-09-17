#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int       val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<void *> s;
        ListNode                  *tmp = head;
        while (tmp != nullptr) {
            if (s.insert((void *)tmp).second == false) return true;
            tmp = tmp->next;
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}