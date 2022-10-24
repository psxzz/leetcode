#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int left = 0, right = 0;
		int min_length = INT_MAX;

		int sum = 0;
		while (right < nums.size()) {
			sum += nums[right];

			while (sum - nums[left] >= target) sum -= nums[left++];

			if (sum >= target)
				min_length = std::min(min_length, right - left + 1);

			right++;
		}

		return min_length == INT_MAX ? 0 : min_length;
	}
};

int main() {
	Solution s;

	vector<int> v1 = {2, 3, 1, 2, 4, 3}, v2 = {1, 4, 4},
				v3 = {1, 1, 1, 1, 1, 1, 1, 1};

	std::cout << s.minSubArrayLen(7, v1) << std::endl;	 // 2
	std::cout << s.minSubArrayLen(4, v2) << std::endl;	 // 1
	std::cout << s.minSubArrayLen(11, v3) << std::endl;	 // 0

	return 0;
}