#include <bits/stdc++.h>

using std::string;

class Solution {
  public:
	int numDecodings(string s) {
		int curr = 1;
		int next = 1;
		int next_next = 1;

		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] == '0')
				curr = 0;
			else
				curr = next;

			if ((i + 1 < s.length()) && s[i] == '1' ||
				(s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
				curr += next_next;

			next_next = next;
			next = curr;
			curr = 1;
		}

		return next;
	}
};

int main() {
	Solution s;

	std::cout << s.numDecodings("12") << std::endl;
	std::cout << s.numDecodings("226") << std::endl;

	return 0;
}