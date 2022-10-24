#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) return mid;

            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] || target < nums[l])
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (target < nums[mid] || target > nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v2 = {1};

    std::cout << s.search(v1, 0) << std::endl;
    std::cout << s.search(v1, 3) << std::endl;
    std::cout << s.search(v2, 0) << std::endl;

    return 0;
}