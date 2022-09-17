#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return -1;
    }
};

int main() {
    Solution s;

    std::vector<int> v1 = {-1, 0, 3, 5, 9, 12};
    std::vector<int> v2 = {5};

    std::cout << s.search(v1, 9) << std::endl;
    std::cout << s.search(v1, 2) << std::endl;
    std::cout << s.search(v2, 5) << std::endl;

    return 0;
}