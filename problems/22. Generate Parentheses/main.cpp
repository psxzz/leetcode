#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
  public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;

		string temp = "";

		std::function<void(int, int)> backtrack = [&backtrack, &n, &res, &temp](
													  int opened, int closed) {
			if (opened == n && closed == n) {
				res.emplace_back(temp);
			}

			if (opened < n) {
				temp.push_back('(');
				backtrack(opened + 1, closed);
				temp.pop_back();
			}

			if (closed < opened) {
				temp.push_back(')');
				backtrack(opened, closed + 1);
				temp.pop_back();
			}
		};

		backtrack(0, 0);

		return res;
	}
};

int main() {
	Solution s;

	auto res = s.generateParenthesis(3);

	return 0;
}