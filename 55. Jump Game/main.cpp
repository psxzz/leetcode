#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] + i >= goal) goal = i;
        }

        return goal == 0;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {2, 3, 1, 1, 4};
    vector<int> v2 = {3, 2, 1, 0, 4};

    std::cout << std::boolalpha << s.canJump(v1) << std::endl;
    std::cout << std::boolalpha << s.canJump(v2) << std::endl;

    return 0;
}