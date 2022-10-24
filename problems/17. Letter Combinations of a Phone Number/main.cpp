#include <bits/stdc++.h>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
  public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;

		std::function<void(int, string&)> backtrack =
			[this, &backtrack, &digits, &res](int i, string& curr) {
				if (curr.length() == digits.length()) {
					res.emplace_back(curr);
					return;
				}
				char digit = digits[i];
				for (auto ch : keyboard[digit]) {
					curr.push_back(ch);
					backtrack(i + 1, curr);
					curr.pop_back();
				}
			};

		if (!digits.empty()) {
			string comb = "";
			backtrack(0, comb);
		}

		return res;
	}

  private:
	unordered_map<char, string> keyboard = {
		{'1', ""},	   {'2', "abc"}, {'3', "def"},	{'4', "ghi"},
		{'5', "jkl"},  {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
		{'9', "wxyz"}, {'0', " "},	 {'*', "+"},	{'#', ""},
	};
};

int main() {
	Solution s;

	auto res = s.letterCombinations("23");

	return 0;
}