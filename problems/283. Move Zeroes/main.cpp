#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (size_t r = 0; r < nums.size(); ++r) {
            if (nums[r]) {
                std::swap(nums[l], nums[r]);
                l++;
            }
        }
    }

    void printVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {0, 1, 0, 3, 12};
    vector<int> v2 = {0};

    s.moveZeroes(v1);
    s.moveZeroes(v2);

    s.printVector(v1);
    s.printVector(v2);

    return 0;
}