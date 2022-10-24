#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
  public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.length() + 1,
							   std::vector<int>(text2.length() + 1, 0));

		for (int i = 1; i <= text1.length(); ++i) {
			for (int j = 1; j <= text2.length(); ++j) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[text1.length()][text2.length()];
	}
};

int main() {
	Solution s;

	std::cout << s.longestCommonSubsequence("abcde", "ace") << std::endl;
	std::cout << s.longestCommonSubsequence("abc", "abc") << std::endl;
	std::cout << s.longestCommonSubsequence("abc", "def") << std::endl;

	return 0;
}