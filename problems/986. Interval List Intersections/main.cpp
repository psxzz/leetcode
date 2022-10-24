#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
											 vector<vector<int>> &secondList) {
		std::vector<vector<int>> res;
		int						 idx1 = 0, idx2 = 0;

		while (idx1 < firstList.size() && idx2 < secondList.size()) {
			int start1 = firstList[idx1][0], end1 = firstList[idx1][1];
			int start2 = secondList[idx2][0], end2 = secondList[idx2][1];
			if (start2 <= end1 && start1 <= end2) {
				int intersectStart = std::max(start1, start2);
				int intersectEnd = std::min(end1, end2);
				res.emplace_back(
					std::initializer_list<int>{intersectStart, intersectEnd});
			}
			if (end1 > end2)
				idx2++;
			else
				idx1++;
		}

		return res;
	}
};

int main() {
	Solution s;

	vector<vector<int>> v1 = {
		{0, 2},
		{5, 10},
		{13, 23},
		{24, 25},
	};

	vector<vector<int>> v2 = {
		{1, 5},
		{8, 12},
		{15, 24},
		{25, 26},
	};

	auto res = s.intervalIntersection(v1, v2);

	return 0;
}