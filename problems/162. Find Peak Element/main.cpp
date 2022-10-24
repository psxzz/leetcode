#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
	int findPeakElement(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;

		while (l <= r) {
			int mid = l + (r - l) / 2;
			if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
				(mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
				return mid;

			if (mid && nums[mid - 1] > nums[mid])
				r = mid - 1;
			else if (mid < nums.size() - 1 && nums[mid + 1] > nums[mid])
				l = mid + 1;
		}

		return l;
	}
};

int main() {
	Solution	s;
	vector<int> v1 = {1, 2, 3, 1};
	vector<int> v2 = {1, 2, 1, 3, 5, 6, 4};
	vector<int> v3 = {1};

	std::cout << s.findPeakElement(v1) << std::endl;
	std::cout << s.findPeakElement(v2) << std::endl;
	std::cout << s.findPeakElement(v3) << std::endl;

	return 0;
}