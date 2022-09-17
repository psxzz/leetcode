#include <iostream>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int pivot = -1;
        int leftSum = 0, rightSum = 0;

        rightSum = std::accumulate(nums.begin() + 1, nums.end(), 0);

        for (int i = 1; i < nums.size(); ++i) {
            if (leftSum == rightSum) return i - 1;

            leftSum += nums[i - 1];
            rightSum -= nums[i];
        }

        if (leftSum == rightSum) return nums.size() - 1;

        return pivot;
    }
};

int main() {
    Solution s;

    std::vector<int> v1 = {1, 7, 3, 6, 5, 6};
    std::vector<int> v2 = {1, 2, 3};
    std::vector<int> v3 = {2, 1, -1};
    std::vector<int> v4 = {-1, -1, 0, 1, 1, 0};
    std::vector<int> v5 = {1, 7, 3, 6, 5, 6};

    std::cout << s.pivotIndex(v1) << std::endl;
    std::cout << s.pivotIndex(v2) << std::endl;
    std::cout << s.pivotIndex(v3) << std::endl;
    std::cout << s.pivotIndex(v4) << std::endl;
    std::cout << s.pivotIndex(v5) << std::endl;

    return 0;
}