#include <bits/stdc++.h>

using std::string;

class Solution {
  public:
	string longestPalindrome(string s) {
		string res = "";
		int	   resLen = 0;
		for (int i = 0; i < s.length(); ++i) {
			int l = i, r = i;
			while (l >= 0 && r < s.length() && s[l] == s[r]) {
				if ((r - l + 1) > resLen) {
					res = string(s.begin() + l, s.begin() + r + 1);
					resLen = r - l + 1;
				}
				l--;
				r++;
			}
			l = i, r = i + 1;
			while (l >= 0 && r < s.length() && s[l] == s[r]) {
				if ((r - l + 1) > resLen) {
					res = string(s.begin() + l, s.begin() + r + 1);
					resLen = r - l + 1;
				}
				l--;
				r++;
			}
		}

		return res;
	}
};

int main() {
	Solution s;

	std::cout << s.longestPalindrome("babad") << std::endl;
	std::cout << s.longestPalindrome("cbbd") << std::endl;

	return 0;
}