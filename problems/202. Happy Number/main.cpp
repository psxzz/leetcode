#include <bits/stdc++.h>

using std::unordered_set;

class Solution {
  public:
	bool isHappy(int n) {
		unordered_set<int> visited;
		while (visited.find(n) == visited.end()) {
			visited.emplace(n);
			int result = 0;

			while (n) {
				int digit = n % 10;
				result += digit * digit;
				n /= 10;
			}

			if (result == 1) return true;
			n = result;
		}

		return false;
	}
};

int main() {
	Solution s;

	std::cout << std::boolalpha << s.isHappy(19) << std::endl;
	std::cout << std::boolalpha << s.isHappy(2) << std::endl;

	return 0;
}