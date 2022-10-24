#include <bits/stdc++.h>

class Solution {
  public:
	int rangeBitwiseAnd(int left, int right) {
		if (left == 0 || right == 0) return 0;

		int counter = 0;
		while (left != right) {
			left >>= 1;
			right >>= 1;
			counter++;
		}

		return left << counter;
	}
};

int main() {
	Solution s;

	std::cout << s.rangeBitwiseAnd(16, 19) << std::endl;

	return 0;
}