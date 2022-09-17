#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        std::stack<int> st;
        int size = 0;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            tmp = tmp->next;
            size++;
        }
        if (size == 1) return true;

        int pivot = (size + 1) / 2;
        if (size % 2 != 0) pivot--;

        size = 0;
        tmp = head;
        while (size < pivot) {
            st.push(tmp->val);
            tmp = tmp->next;
            size++;
        }

        while (tmp != nullptr) {
            if (tmp->val == st.top())
                st.pop();
            tmp = tmp->next;
        }

        return st.empty();
    }
};

int main() {
    Solution s;

    ListNode *l1 = new ListNode(1, new ListNode(2));
    ListNode *l2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    ListNode *l3 = new ListNode(1, new ListNode(0, new ListNode(1)));

    std::cout << std::boolalpha << s.isPalindrome(l1) << std::endl;
    std::cout << std::boolalpha << s.isPalindrome(l2) << std::endl;
    std::cout << std::boolalpha << s.isPalindrome(l3) << std::endl;

    return 0;
}