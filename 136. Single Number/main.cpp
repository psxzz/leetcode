#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (auto num : nums) {
            res ^= num;
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {2, 2, 1};

    std::cout << s.singleNumber(v1) << std::endl;

    return 0;
}