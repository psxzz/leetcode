#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int front;
        int curr;

        for (int i = n - 1; i >= 0; --i) {
            front = nums.front();
            curr = nums[i];
            if (front * front <= curr * curr) {
                nums[i] *= nums[i];
            } else {
                nums[0] = nums[i];
                nums[i] = front;
                nums[i] *= nums[i];
            }
        }

        std::sort(nums.begin(), nums.end());

        return nums;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {-4, -1, 0, 3, 10};
    vector<int> v2 = {-5, -3, -2, -1};
    // 16 10 => -4 -1 0 3 10
    // 16 9 => 3 -1 0 -4 10
    // 9 16 => 3 -1 0 -4 10
    // 9 0 => 0 -1 3 -4 10
    // 0 1 => 0 -1 3 -4 10
    // 0 0
    vector<int> res = s.sortedSquares(v2);

    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}