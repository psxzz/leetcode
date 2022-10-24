#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
  public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;

		int p_freq[26] = {0};
		for (auto &ch : p) {
			p_freq[ch - 'a']++;
		}

		int left = 0, right = 0;
		int count = p.length();

		while (right < s.length()) {
			if (p_freq[s[right++] - 'a']-- >= 1) count--;

			if (count == 0) res.push_back(left);

			if (right - left == p.length() && p_freq[s[left++] - 'a']++ >= 0)
				count++;
		}

		return res;
	}
	void printVector(vector<int> &v) {
		for (auto &i : v) {
			std::cout << i << " ";
		}

		std::cout << std::endl;
	}
};

int main() {
	Solution s;

	auto res = s.findAnagrams("cbaebabacd", "abc");

	return 0;
}