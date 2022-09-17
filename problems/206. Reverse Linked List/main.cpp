#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* out = new ListNode(-1);
        ListNode* tmp = head;
        if (head == nullptr) return nullptr;

        while (tmp != nullptr) {
            ListNode* outnext = out->next;
            out->next = tmp;
            tmp = out->next->next;
            out->next->next = outnext;
        }

        return out->next;
    }

    void printList(ListNode* l) {
        while (l != nullptr) {
            std::cout << l->val << " ";
            l = l->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* res = s.reverseList(l1);

    s.printList(res);

    delete l1;
    // delete l2;

    return 0;
}