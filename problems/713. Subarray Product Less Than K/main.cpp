#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int numSubarrayProductLessThanK(vector<int> &nums, int k) {
		if (k <= 1) return 0;

		int result = 0;
		int prod = 1;

		int left = 0, right = 0;

		while (right < nums.size()) {
			prod *= nums[right];

			while (prod >= k) prod /= nums[left++];

			result += right - left + 1;
			right++;
		}

		return result;
	}
};

int main() {
	Solution s;

	vector<int> v1 = {10, 5, 2, 6}, v2 = {1, 2, 3};

	std::cout << s.numSubarrayProductLessThanK(v1, 100) << std::endl;
	std::cout << s.numSubarrayProductLessThanK(v2, 0) << std::endl;

	return 0;
}