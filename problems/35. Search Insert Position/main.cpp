#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 3, 5, 6};
    std::cout << s.searchInsert(v1, 5) << std::endl;
    std::cout << s.searchInsert(v1, 2) << std::endl;
    std::cout << s.searchInsert(v1, 7) << std::endl;

    return 0;
}