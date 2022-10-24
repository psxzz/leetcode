#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] < nums[r])
				r = mid;
			else
				l = mid + 1;
		}

		return nums[r];
	}
};

int main() {
	Solution s;

	vector<int> v1 = {3, 4, 5, 1, 2};
	vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};
	vector<int> v3 = {11, 13, 15, 17};
	vector<int> v4 = {3, 1, 2};

	std::cout << s.findMin(v1) << std::endl;
	std::cout << s.findMin(v2) << std::endl;
	std::cout << s.findMin(v3) << std::endl;
	std::cout << s.findMin(v4) << std::endl;

	return 0;
}