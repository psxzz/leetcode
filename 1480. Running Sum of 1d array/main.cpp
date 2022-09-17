#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution s;

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {1, 1, 1, 1, 1};
    std::vector<int> v3 = {3, 1, 2, 10, 1};

    vector<int> res1 = s.runningSum(v1);
    vector<int> res2 = s.runningSum(v2);
    vector<int> res3 = s.runningSum(v3);

    print_vector(res1);
    print_vector(res2);
    print_vector(res3);

    return 0;
}