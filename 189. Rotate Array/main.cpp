#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i++) {
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    // 1, 2, 3, 4, 5, 6, 7
    // 1, 2, 3, 4, 5, 6, 7
    // 1, 2, 3, 4, 5, 6, 7
    // 1, 2, 3, 4, 5, 6, 7
    // 5, 6, 7, 1, 2, 3, 4

    s.rotate(v1, 3);

    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}