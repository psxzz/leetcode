#include <bits/stdc++.h>

#include <cstddef>

/*
// Definition for a Node.
*/
class Node {
  public:
	int	  val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node *_left, Node *_right, Node *_next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
	Node *connect(Node *root) {
		if (!root) return nullptr;

		Node *head = root;

		while (head) {
			Node *dummy = new Node(0);
			Node *temp = dummy;
			while (head) {
				if (head->left) {
					temp->next = head->left;
					temp = temp->next;
				}
				if (head->right) {
					temp->next = head->right;
					temp = temp->next;
				}
				head = head->next;
			}

			head = dummy->next;
		}

		return root;
	}
};

int main() {
	Solution s;

	Node *t = new Node(1, new Node(2, new Node(4), new Node(5), NULL),
					   new Node(3, NULL, new Node(7), NULL), NULL);
	Node *t2 = new Node(
		1, new Node(2, new Node(4, new Node(7), NULL, NULL), new Node(5), NULL),
		new Node(3, NULL, new Node(6, NULL, new Node(8), NULL), NULL), NULL);

	Node *res = s.connect(t2);

	return 0;
}