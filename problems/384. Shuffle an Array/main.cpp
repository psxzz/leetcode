#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	Solution(vector<int>& nums) : nums_(nums) {}

	vector<int> reset() { return nums_; }

	vector<int> shuffle() {
		vector<int> res(nums_);

		for (int i = res.size() - 1; i > 0; --i) {
			int j = rand() % (i + 1);

			std::swap(res[i], res[j]);
		}

		return res;
	}

  private:
	vector<int> nums_;
};

int main() {
	vector<int> v1{1, 2, 3};
	Solution	s(v1);

	return 0;
}