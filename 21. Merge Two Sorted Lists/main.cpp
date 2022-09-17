#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* out = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if (list1) head->next = list1;
        if (list2) head->next = list2;

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
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* res = s.mergeTwoLists(l1, l2);

    s.printList(res);

    delete l1;
    delete l2;

    return 0;
}