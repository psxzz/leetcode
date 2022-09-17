#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0;
        int len = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                pos = neg = 0;
            } else if (nums[i] < 0) {
                std::swap(pos, neg);
                neg++;
                if (pos) pos++;
            } else {
                pos++;
                if (neg) neg++;
            }

            len = std::max(len, pos);
        }

        return len;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, -2, -3, 4};
    vector<int> v2 = {0, 1, -2, -3, -4};
    vector<int> v3 = {-1, -2, -3, 0, 1};

    std::cout << s.getMaxLen(v1) << std::endl;
    std::cout << s.getMaxLen(v2) << std::endl;
    std::cout << s.getMaxLen(v3) << std::endl;

    return 0;
}