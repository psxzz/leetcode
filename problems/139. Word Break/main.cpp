#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
  public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length() + 1, false);
		dp[s.length()] = true;

		for (int i = s.length() - 1; i >= 0; --i) {
			for (auto& word : wordDict) {
				if (s.substr(i, word.length()) == word) {
					dp[i] = dp[i + word.length()];
					if (dp[i]) break;
				}
			}
		}

		return dp[0];
	}
};

int main() {
	Solution s;

	vector<string> v1 = {"leet", "code"}, v2 = {"a", "abc", "b", "cd"},
				   v3 = {"car", "ca", "rs"};
	std::cout << std::boolalpha << s.wordBreak("leetcode", v1) << std::endl;
	std::cout << std::boolalpha << s.wordBreak("neetcode", v1) << std::endl;
	std::cout << std::boolalpha << s.wordBreak("abcd", v2) << std::endl;
	std::cout << std::boolalpha << s.wordBreak("cars", v3) << std::endl;

	return 0;
}